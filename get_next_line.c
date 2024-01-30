/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:23:43 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/30 19:51:56 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	free_all(char *s)
{
	free(s);
	s = NULL;
}

static char	*read_fd(int fd, char *buffer, char *prev_line)
{
	int		i;
	char	*line;

	i = 1;
	while (i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		else if (i == 0)
			break ;
		buffer[i] = '\0';
		if (!prev_line)
			prev_line = ft_strdup("");
		line = prev_line;
		prev_line = ft_strjoin(line, buffer);
		free_all(line);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (prev_line);
}

static char *function_name(char *line)
{
	size_t	i;
	char	*res;

	i = 0;
	while (line[i] && line[i]!= '\n')
		i++;
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*prev_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_fd(fd, buffer, prev_line);
	free_all(buffer);
	prev_line = function_name(line);
	return (line);
}
