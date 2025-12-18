*Este proyecto ha sido creado como
parte del currículo de 42 por cpicon-m*
# get_next_line

## Descripción

Es una función que extrae una línea de un archivo.
La lectura se detiene al encontrar '\n' o EOF.
cada llamada devuelve a la siguiente linea del archivo, en otras palabras
Devuelve la linea que almacena, y apunta directamente a la siguiente.

## Instrucciones

### Compilación

Para compilar la función junto con tu código, utiliza el siguiente comando:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c main.c -o gnl
```
### Ejecucion

```bash
./gnl test.txt
```
### Ejemplo

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
### main
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```
## Recursos
### Referencias

    Documentación oficial de read(2): Consulta de la página de manual para entender el comportamiento de las lecturas y los valores de retorno.

    Variables estáticas en C: Estudio sobre el tiempo de vida y el alcance de las variables static en C, fundamentales para la persistencia de la stash.

    Manejo de File Descriptors: Información sobre cómo el sistema operativo gestiona los descriptores de archivo y sus límites.

    Norminette: Documentación sobre las reglas de estilo y formato de código exigidas en 42.

### Uso de IA

Se ha utilizado inteligencia artificial (Gemini) para las siguientes tareas:

    Estructuración del README: Organización de secciones según los requisitos del currículo y formato Markdown.

    Explicación teórica: Clarificación de conceptos técnicos como el funcionamiento de la variable estática stash y la aritmética de punteros en la reserva de memoria (stash + i).

    Optimización de lógica: Apoyo en la comprensión del flujo de liberación de memoria en funciones de limpieza como free_stash.
## funciones

## Justificación del Algoritmo

Se ha elegido un algoritmo basado en una variable estática (stash) por las siguientes razones:

    Persistencia de datos: Al ser una función que puede llamarse múltiples veces, la variable estática permite "recordar" el exceso de bytes leídos en la llamada anterior que pertenecen a la siguiente línea.

    Modularidad: El proceso se divide en tres pasos claros: lectura hasta encontrar un salto de línea (get_buffer_to_stash), extracción de la línea para el usuario (return_line) y limpieza del almacén para futuras llamadas (free_stash).

    Gestión de memoria: El uso de una variable estática única optimiza el uso de memoria frente a otras soluciones más complejas, permitiendo liberar y reasignar solo el espacio estrictamente necesario en cada paso.
### get_next_line
```c
char	*get_next_line(int fd)
```
Funcion que se le pasa un fichero,, comprobaciones de errores basicas que retornaran NULL en caso de error.

`static stash` = es la variable que se encarga de almacenar el restante del read. Puede contener restos de siguientes lineas y demas, es estatica debido a que tiene que 'recordar', la llamada anterior.

`line` = es la  variable que se retorna, ya recortada.

```c 
stash = get_buffer_to_stash(fd, stash);
```
Esta llamada a get_buffer_to_stash, se encarga de coger el contenido de buffer(cantidad de bytes leidos	cada que se usa read).
se le pasa el bloque de memoria en buffer y stash almacena el conenido de buffer hasta encontrar \n o EOF

```c
line = return_line(stash);
```
Esta llamada, se encarga de copiar el contenido de stash en line, hasta encontrar \0 o \n.

```c
stash = free_stash(stash);
```
Esta llama se encarga de liberar el contenido de stash, conseravando unicamente el contenido, de despues de /n y eliminando el resto, 
