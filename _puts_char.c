#include "shell.h"

/**
 * putStrng - Prints an input string to the standard output.
 * @str: The string to be printed.
 *
 * Return: Nothing (void).
 * Author: Isaac and Nnon
 */
void putStrng(char *str)
{
	int o;

	o = 0;
	if (str == NULL)
	{
		return;
	}
	while (str[o] != '\0')
	{
		put_caracter(str[o]);
		o++;
	}
}

/**
 * put_caracter - Writes the character 'c' to the std output.
 * @c: The character to print.
 *
 * Return: On success, 1. On error, -1 is returned
 * Author: Isaac and Nnon
 */
int put_caracter(char c)
{
	static char buffa[WRITE_BUF_SIZE];
	static int o;

	if (c == BUF_FLUSH || o >= WRITE_BUF_SIZE)
	{
		write(1, buffa, o);
		o = 0;
	}
	if (c != BUF_FLUSH)
	{
		buffa[o++] = c;
	}
	return (1);
}
