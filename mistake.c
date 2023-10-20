#include "shell.h"
/**
 * in_puts - writes the character c to given fd
 * @a: is the character to print
 * @fd: is the filedescriptor to write to
 * Return: as specified
 */
int in_puts(char a, int fd)
{
	static int j;
	static char buffer[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buffer, j);
		j = 0;
	}
	if (j != BUF_FLUSH)
		buffer[j++] = a;
	return (1);
}

/**
 * _putin - is a function prints an input string
 * @input: is the pointer the string to be printed
 * @fd: is the filedescriptor to write to
 * Return: the number of chars put
 */
int _putin(char *input, int fd)
{
	int j = 0;

	if (!input)
		return (0);
	while (*input)
	{
		j += in_puts(*input++, fd);
	}
	return (j);
}
