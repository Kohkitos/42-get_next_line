/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:15:35 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/24 13:16:45 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d_cpy;
	unsigned char	*s_cpy;

	if (!dest && !src)
		return (dest);
	d_cpy = dest;
	s_cpy = (unsigned char *)src;
	while (n > 0)
	{
		*d_cpy = *s_cpy;
		d_cpy++;
		s_cpy++;
		n--;
	}
	return (dest);
}