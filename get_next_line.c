/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:47:23 by raulp             #+#    #+#             */
/*   Updated: 2025/11/05 14:00:06 by raulp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// the ** means that i get the real ptr, if i only put * i get a cpy
char *get_line(char *buffer, char **rest)
{
	char	*pos;
	int		i;
	if(!buffer)
		return (NULL);
	pos = ft_strchr(buffer,'\n');
	// means that if pos isnt null, i.e., if pos found /n. 
	// found, and rest. to set the i position in the buffer
	if(pos != NULL)
	{
		i = pos - buffer;
	}
	else
	{
		// i is the size of the buffer, so...
		i = ft_strlen(buffer);
		// here i connect the buffer and the new content
		rest = ft_strjoin(rest, buffer);
	}
	
	

}


char *get_next_line(int fd)
{
	char *buffer;
	static int read_bytes;
	static char *rest;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
		// we put +1 for the \0
	buffer = l(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
	{
		free(buffer);
		return (NULL);
	}
	// for create a limit, and declare a valid line on c
	buffer[read_bytes] = '\0';

	
	line 
}
