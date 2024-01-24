/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:15:35 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/24 18:28:39 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (s2);
	else if (!s2)
		return (s1);
	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	len_s2 = 0;
	while (s1[len_s2])
		len_s2++;
	ptr = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len_s1 + 1);
	ft_strlcpy(ptr + len_s1, s2, len_s2 + 1);
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
