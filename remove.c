#include "shell.h"

/**
 * rem_comment - function replaces '#' with empty
 * @buf: address of the string to replace or remove
 * Return: as specified
 * Authors: Isaac and NNon
 */
void rem_comment(char *buf)
{
	int i = 0;

	while (buf[i] != '\0')
	{
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
		i++;
	}
}

