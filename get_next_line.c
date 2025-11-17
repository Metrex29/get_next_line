/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:47:23 by raulp             #+#    #+#             */
/*   Updated: 2025/11/12 15:30:15 by raulp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_join_lines(int fd, char **stash, char *buffer)
{
	int read_bytes;

	read_bytes = 1;
	while(!ft_strchr(*stash, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if(read_bytes == -1)
			{
				free(*stash);
				*stash = NULL;
				return ;
			}
		buffer[read_bytes] = '\0';
		
	}
		
}

char *get_next_line(int fd)
{
	static char *stash;
	char *buffer;
	char *line;
	size_t read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

}
