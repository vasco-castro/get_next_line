/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:13:48 by vsoares-          #+#    #+#             */
/*   Updated: 2024/12/02 16:16:51 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			c_read;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (buf[fd][0])
		c_read = 1;
	else
		c_read = read(fd, buf[fd], BUFFER_SIZE);
	while (c_read > 0)
	{
		line = str_append(line, buf[fd]);
		if (!line)
			return (NULL);
		if (line[line_len(line)] == '\n')
			return (line);
		c_read = read(fd, buf[fd], BUFFER_SIZE);
	}
	if (c_read < 0)
		return (free(line), NULL);
	return (line);
}
