/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:47:23 by raulp             #+#    #+#             */
/*   Updated: 2025/12/10 15:25:46 by raulp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static char	*ft_free_leak(char *arr)
{
	free(arr);
	return (NULL);
}

static char	*get_buffer_to_stash(char *stash, int fd)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free_leak(stash));
	if (!stash)
		stash = ft_strdup("");
	read_bytes = 1;
	while (!ft_strchr(stash, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (ft_free_leak(stash));
		}
		if( read_bytes == 0 )
			break ;
		buffer[read_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		if(!stash)
		{
			free(buffer);
			return (ft_free_leak(stash));
		}
	}
	free(buffer);
	return (stash);
}

static char	*return_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	if (stash[i] == '\n')
	{
		line[j] = stash[i];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*free_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;
	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (ft_free_leak(stash));
	new_stash = malloc(ft_strlen(stash) - i + 1);
	if (!new_stash)
		return (ft_free_leak(stash));
	i++;
	while (stash[i])
	{
		new_stash[j++] = stash[i++];
	}
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_buffer_to_stash(stash, fd);
	if (!stash)
		return (NULL);
	line = return_line(stash);
	if (!line)
	{
		stash = free_stash(stash);
		return (NULL);
	}
	stash = free_stash(stash);
	return (line);
}