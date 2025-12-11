#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;
    int n = 0;

    if (argc < 2)
    {
        fd = 0;
        fprintf(stderr, "Leyendo stdin (Ctrl+D para EOF)...\n");
    }
    else
        fd = open(argv[1], O_RDONLY);

    if (fd < 0)
    {
        perror("open");
        return (1);
    }

    while ((line = get_next_line(fd)))
    {
        printf("LINE %d (len=%zu): ", ++n, strlen(line));
        fwrite(line, 1, strlen(line), stdout);
        printf("\nHEX: ");
        for (size_t i = 0; line[i]; i++)
            printf("%02x ", (unsigned char)line[i]);
        printf("\n\n");
        free(line);
    }
    printf("Fin, líneas leídas: %d\n", n);
    if (argc >= 2)
        close(fd);
    return (0);
}