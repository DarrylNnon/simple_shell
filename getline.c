#include "shell.h"
#include <unistd.h>

/**
 * _getline - reads an entire line from stdin
 * Return: pointer to the line read, or NULL on error or when no more lines
 * Author: Nnon and Isaac
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char _getline(size_t *size)
{
    static char buffer[BUFFER_SIZE];
    static char *start = buffer;
    static char *last = buffer + BUFFER_SIZE;

    if (start == last) 
    {
        ssize_t read_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        if (read_size == 0)
            return NULL;
        if (read_size < 0)
       	{
            perror("read");
            exit(EXIT_FAILURE);
        }
        start = buffer;
        last = buffer + read_size;
    }

    char *mid = start;

    while (start < last && *start != '\n')
        start++;

    if (start < last)
        *start++ = '\0';
    else
        *start = '\0';

    size_t line_size = start - mid;
    char *line = malloc(line_size + 1);

    if (!line)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    memcpy(line, mid, line_size + 1);

    *size = line_size;
    return line;
}

