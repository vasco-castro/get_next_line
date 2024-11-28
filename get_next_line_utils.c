/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:13:54 by vsoares-          #+#    #+#             */
/*   Updated: 2024/11/28 17:50:07 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	ft_bzero(void *s, size_t n)
{
	char	*src;

	src = (char *)s;
	while (n-- > 0)
		*(src++) = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;
	size_t	total_size;

	total_size = count * size;
	if (count && ((total_size / count) != size))
		return (NULL);
	alloc = malloc(total_size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, total_size);
	return (alloc);
}

// char	*salloc(size_t count)
// {
// 	char	*alloc;
// 	size_t	i;

// 	alloc = malloc(count);
// 	if (!alloc)
// 		return (NULL);
// 	i = count;
// 	while (i-- > 0)
// 		*(alloc++) = '\0';
// 	return (alloc);
// }

char	*memshift(char *dst, const char *src, size_t n)
{
	char	*tmp_dst;
	char	*tmp_src;

	if (!src && !dst)
		return (NULL);
	tmp_dst = (char *) dst;
	tmp_src = (char *) src;
	while (n-- > 0)
		*(tmp_dst++) = *(tmp_src++);
	*tmp_dst = 0;
	return (dst);
}

char	*str_append(char *old_line, char *buf)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_line = ft_calloc(line_len(old_line) + line_len(buf) + 2, 1);
	if (!new_line)
		return (NULL);
	while (old_line && old_line[i])
	{
		new_line[i] = old_line[i];
		i++;
	}
	while (buf[j] && buf[j] != '\n')
		new_line[i++] = buf[j++];
	if (buf[j] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	buf = memshift(buf, buf + j + 1, BUFFER_SIZE - j);
	free(old_line);
	return (new_line);
}
