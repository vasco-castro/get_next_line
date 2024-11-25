/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:13:48 by vsoares-          #+#    #+#             */
/*   Updated: 2024/11/25 23:02:21 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE /* + 1 */];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);

	// printf("|BUFFER: %s|\n", buf);
	line = malloc(BUFFER_SIZE + 2);
	if (!line)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		line = str_append(line, buf);
		// printf("|BUFFER: %s|\n", buf);
		if (!line)
			return (NULL);
		if (check_nl(line))
			return (line);
	}
	return (line);
}
