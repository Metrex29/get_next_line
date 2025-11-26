/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:47:23 by raulp             #+#    #+#             */
/*   Updated: 2025/11/26 12:23:09 by raulp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_buffer_to_stash(char *stash, int fd)
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
	// what the user get
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_buffer_to_stash(fd, stash);
	// read and full stash
	if (!stash)
		return (NULL);
}
