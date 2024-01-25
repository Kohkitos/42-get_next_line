/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:15:35 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/25 09:38:35 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	char	*cpy;
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	if (!size)
		return (len);
	cpy = (char *)src;
	while ((size > 1) && (*cpy))
	{
		*dst = *cpy;
		dst++;
		cpy++;
		size--;
	}
	if (*dst)
		*dst = 0;
	return (len);
}

char	*ft_strjoin(char *line, char *buffer)
{
	size_t	len_line;
	size_t	len_buffer;
	char	*ptr;

	if (!line && !buffer)
		return (NULL);
	else if (!line)
	{
		ptr = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		ft_strlcpy(ptr, buffer, BUFFER_SIZE + 1);
		free (buffer);
		return (ptr);
	}
	else if (!buffer)
		return (line);
	len_line = 0;
	while (line[len_line])
		len_line++;
	len_buffer = 0;
	while (line[len_buffer])
		len_buffer++;
	ptr = ft_calloc(sizeof(char), (len_line + len_buffer + 1));
	ft_strlcpy(ptr, line, len_line + 1);
	ft_strlcpy(ptr + len_line, buffer, len_buffer + 1);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char			*cpy;
	unsigned char	ch;

	ch = (unsigned char)c;
	cpy = (char *)s;
	while ((*cpy != ch) && *cpy)
		cpy++;
	if (ch == *cpy)
		return (cpy);
	return (NULL);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	n;

	if (nmemb >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	n = size * nmemb;
	ptr = malloc(n);
	if (!ptr)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		ptr[i] = 0;
		i++;
		n--;
	}
	return (ptr);
}
