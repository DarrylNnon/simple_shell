#include "shell.h"

/**
 *_puth - is used to prints an input string
 * @input: is the pointer to string  print
 * Return: as specified
 * Authors: Isaac and Nnon
 */
void _puth(char *input)
{
	int j = 0;

	if (!input)
		return;
	while (input[j] != '\0')
	{
		_putcar(input[j]);
		j++;
	}
}

/**
 * _putcar - is the func writes the character c to stderr
 * @c: is the defined character to print
 * Return: as specified
 */
int _putcar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

