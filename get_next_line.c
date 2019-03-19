/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:45:49 by snechaev          #+#    #+#             */
/*   Updated: 2019/03/12 13:00:00 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_end(char **line, char *dep)
{
	int	i;
	char	*tmp;
	
	i = 0;
	while (dep[i] != '\n' && dep)
		i++;
	if (dep[i] == '\n')
	{
		*line = ft_strsub(dep, 0, i);
		tmp = ft_strdup(&dep[i + 1]);
		ft_strdel(&dep);
		dep = tmp;
	}
	else
	{
		*line = ft_strdup(dep);
		ft_strdel(&dep);
	}
	return (1);
}

int	file_read(const int fd, char **line, char *dep)
{
	char	buff[BUFF_SIZE + 1];
	int	nread;
	char	*tmp;
	
	while ((nread = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[BUFF_SIZE] = '\0';
		tmp = ft_strjoin(dep, buff);
		ft_strdel(dep);
		if (ft_strchr(buff, '\n'))
			break;
	}
	if (nread < 0)
		return (-1);
	else if(nread == 0 && dep[0] == '\0')
		return (0);
	return (find_end(line, dep));
}

int	get_next_line(const int fd, char **line)
{
	static char	dep;

	if (!fd || !line || fd > MAX_FD)
		return (-1);
	if (!dep)
		dep = ft_strnew(1);
	return (file_read(fd, line, dep));
}
