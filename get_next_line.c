	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   get_next_line.c                                    :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2025/11/03 15:47:23 by raulp             #+#    #+#             */
	/*   Updated: 2025/11/04 16:13:04 by raulp            ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

	#include "get_next_line.h"

	// buffer delaration
	// if... size
	// control if malloc work!;
	// we put de same buffer size at the declaration of de read, because read only read size_t nt char*
	//
	char *get_next_line(int fd)
	{
		char *buffer;
		static int read_bytes;
		static char *ptr;

		if (fd < 0 || BUFFER_SIZE <= 0)
			return (NULL);
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			return (NULL);
			free(buffer);
		}
		// for create a limit, and declare a valid line on c
		buffer[read_bytes] = '\0';


	}

