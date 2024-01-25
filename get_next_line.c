/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:23:43 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/25 09:38:15 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_fd(int fd, char *line)
{
	char	buf[BUFFER_SIZE + 1];
	int		i;

	if (!line)
		line = ft_calloc(1, sizeof(char));
	i = 1;
	while (i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		printf("%s\n", buf);
		if (i < 0)
		{
			free (line);
			return (NULL);
		}
		buf[i] = '\0';
		line = ft_strjoin(line, buf);
		printf("%s\n", line);
		if (ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = read_fd(fd, line);
	if (!line)
		return (NULL);
	return (line);
}
