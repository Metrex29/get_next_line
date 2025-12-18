/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:47:23 by raulp             #+#    #+#             */
/*   Updated: 2025/12/18 09:58:26 by cpicon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_free_leak(char *arr)
{
	free(arr);
	return (NULL);
}

static char	*get_buffer_to_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free_leak(stash));
	read_bytes = 1;
	while (!stash || !ft_strchr(stash, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (ft_free_leak(stash));
		}
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (ft_free_leak(buffer));
	}
	free(buffer);
	return (stash);
}

static char	*return_line(char *stash)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	len = i;
	if (stash[i] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line + j, stash + j, i - j);
	j = i;
	if (stash[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

static char	*free_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (ft_free_leak(stash));
	i++;
	if (!stash[i])
		return (ft_free_leak(stash));
	new_stash = malloc(ft_strlen(stash + i) + 1);
	if (!new_stash)
		return (ft_free_leak(stash));
	while (stash[i])
		new_stash[j++] = stash[i++];
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
	stash = get_buffer_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = return_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = free_stash(stash);
	return (line);
}
