# get_next_line

## Descripción

Es una función que extrae una línea de un archivo.
La lectura se detiene al encontrar '\n' o EOF.
cada llamada devuelve a la siguiente linea del archivo, en otras palabras
Devuelve la linea que almacena, y apunta directamente a la siguiente.

## Ejemplo

```c
// Archivo fd.txt:
// Hola
// Mundo
// 42
int ejemplo = open("fd.txt", O_RDONLY);
char *line;

line = get_next_line(fd); // return "Hola\n"
line = get_next_line(fd); // return "Mundo\n"
line = get_next_line(fd); // return "42"
line = get_next_line(fd); // return NULL
// (fin del archivo)
```
## Compilación
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c main.c -o gnl
```
## main


