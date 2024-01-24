/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:23:43 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/24 13:13:11 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_n(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '/n')
			return (i);
		i++;
	}
	return (0);
}

static void	read_fd(int fd, char *buffer)
{
	int	i;

	if (!buffer)
		buffer = 0;
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		i = check_n(buffer);
		if (i)
			break ;
		i = -1;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0)
		return (NULL);
	read_fd(fd, buffer);
	return (NULL);
}
