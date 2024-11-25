/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:13:54 by vsoares-          #+#    #+#             */
/*   Updated: 2024/11/25 22:07:29 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*str_append(char *old_line, char *buf)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!old_line || !buf)
		return (NULL);
	new_line = (char *)malloc(str_len(old_line) + str_len(buf) + 2);
	if (!new_line)
		return (NULL);
	while (old_line[i])
	{
		new_line[i] = old_line[i];
		i++;
	}
	while (buf[j] && buf[j] != '\n')
		new_line[i++] = buf[j++];
	if (buf[j] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	free(old_line);
	return (new_line);
}

char	*check_nl(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	line[++i] = 0;
	return (line);
}
