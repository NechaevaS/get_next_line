/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:45:49 by snechaev          #+#    #+#             */
/*   Updated: 2019/03/08 14:47:40 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE + 1];
	char	*tmp;
	char	*tmp1;
	int		nread;
	char	*pn;
	int		ntail;


	if (!fd || !line)
		return (-1);
//	buff[BUFF_SIZE] = '\0';
	*line = ft_strdup("");
	while ((nread = read(fd, buff, BUFF_SIZE)) > 0)
	{
		pn = ft_strchr(buff, '\n');
		if (pn != NULL)
		{
			tmp = (char *)malloc(pn - buff + 1);
			if (!tmp)
				return	(-1);
			tmp = ft_strncpy(tmp, buff, pn - buff);
			tmp[pn - buff] = '\0';
			tmp1 = *line;
			*line = ft_strjoin(*line, tmp);
			free (tmp1);
			ntail = &(buff[BUFF_SIZE - 1]) - pn;
			ft_memmove(buff, pn, ntail);
			nread = read(fd, buff + ntail, BUFF_SIZE - ntail);
			return (1);
		}
		tmp = *line;
		*line = ft_strjoin(tmp, buff);
		free (tmp);

	}
	if (nread < 0)
		return (-1);
	if (nread == 0)
		return (0);
}
