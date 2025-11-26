/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:47:23 by raulp             #+#    #+#             */
/*   Updated: 2025/11/26 15:55:03 by raulp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_buffer_to_stash(char *stash, int fd)
{
	// get the informaction until size
	char *buffer;
	int read_bytes;

	read_bytes = 1;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (read_bytes == -1)
		{
			free(buffer);
			return NULL;
		}
	}
	free(buffer);
	return stash;
}

static char *return_line(char *stash)
{
	int i;
	int j;
	char *line;

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

/* stash =
1- accumulator storage all the lines, until they found the /n,
	2- plus, when the functions ends, extract the line, and update stash
		to only storage the excedent
*/
/* buffer =
	1- use read, to read the file fd
	2- limit size
	3-  amnesia

 */

char *get_next_line(int fd)
{
	// read and storage
	static char *stash;
	char *line;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_buffer_to_stash(stash,fd);
	// read and full stash
	if (!stash)
		return (NULL);
	// 2. Paso: Extraer la línea (te falta esta función)
	line = return_line(stash);
	// 3. Paso: Limpiar stash (te falta esta función)
	// stash = clean_stash(stash);
	return line;
}
