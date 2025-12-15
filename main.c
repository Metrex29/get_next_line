#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc < 2)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}

	while ((line = get_next_line(fd)))
	{
		/* imprimir exactamente el contenido devuelto por get_next_line */
		fputs(line, stdout);
		free(line);
	}

	if (argc >= 2)
		close(fd);
	return (0);
}