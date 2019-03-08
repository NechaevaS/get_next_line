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
	int		nread;
	char	*pn;
	int		ntail;


	if (!fd || !line)
		return (-1);
	buff[BUFF_SIZE] = '\0';
	nread  = read(fd, buff, BUFF_SIZE);
	if (nread < 0)
		return (-1);
	line = NULL;
	while (nread > 0)
	{
		pn = ft_strchr(buff, '\n');
		if (pn != NULL)
		{
			tmp = (char *)malloc(pn - buff + 1);
			if (!tmp)
				return	(NULL);
			tmp = ft_strcpy(tmp, buff);
			*line = tmp;
			return (1);
		}
		else
		{
			tmp = ft_strdup(buff);
			*line = ft_strjoin(*line, tmp);
		}
		ntail = &(buff[BUFF_SIZE - 1]) - pn;
		buff = ft_memmove(buff, pn, ntail);
		nread = read(fd, buff + ntail, BUFF_SIZE - ntail);
		free(tmp);
		free(pn);
	}
	if (nread == 0)
		return (0);
}
