#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _getline - is the function used for getting input
 * @size: is the pointer used
 * Return: as specified
 * Author: Nnon and Isaac
 */
char *_getline(size_t *size)
{
	static char buffer[BUFFER_SIZE];
	static char *start = buffer;
	static char *last = buffer + BUFFER_SIZE;
	char *mid;
	size_t line_size;
	char *line;

	if (start == last)
	{
		ssize_t read_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (read_size == 0)
			return (NULL);
		if (read_size < 0)
		{
			perror("read");
			return (NULL);
		}
		last = buffer + read_size;
		start = buffer;
	}
	mid = start;
	while (start < last && *start != '\n')
		start++;
	if (start < last)
		start++;
	else
		start = last;
	line_size = start - mid;
	line = malloc(line_size + 1);
	if (!line)
	{
		perror("malloc");
		return (NULL);
	}
	memcpy(line, mid, line_size);
	line[line_size] = '\0';
	*size = line_size;
	return (line);
}

