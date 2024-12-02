/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:13:54 by vsoares-          #+#    #+#             */
/*   Updated: 2024/12/02 16:16:47 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	line_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	bufshift(char *buf, size_t size)
{
	int	i;

	i = 0;
	while (buf[size])
		buf[i++] = buf[size++];
	while (i < BUFFER_SIZE)
		buf[i++] = 0;
}

char	*str_append(char *old_line, char *buf)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_line = malloc(line_len(old_line) + line_len(buf) + 2);
	if (!new_line)
		return (NULL);
	while (old_line && old_line[i])
	{
		new_line[i] = old_line[i];
		i++;
	}
	while (buf[j] && buf[j - 1] != '\n')
		new_line[i++] = buf[j++];
	new_line[i] = 0;
	bufshift(buf, j);
	free(old_line);
	return (new_line);
}
