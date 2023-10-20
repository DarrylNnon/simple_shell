#include "shell.h"

/**
 * strncoppi - Copies a string from source to destination.
 * @dest: The destination where the string will be copied.
 * @src: The source string to be copied.
 *
 * Return: A pointer to the destination string.
 * string1.c
 */
char *strncoppi(char *dest, char *src)
{
	int x;

	if (dest == src || src == 0)
		return (dest);
	for (x = 0; src[x]; x++)
	{
		dest[x] = src[x];
	}
	dest[x] = 0;
	return (dest);
}

/**
 * strnrwnp - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string.
 * string1.c
 */
char *strnrwnp(const char *str)
{
	char *ret;
	int lernt;

	lernt = 0;
	if (!str)
	{
		return (NULL);
	}
	while (*str++)
		lernt++;
	ret = malloc(sizeof(char) * (lernt + 1));
	if (ret == NULL)
	{
		return (NULL);
	}
	for (lernt++; lernt--;)
		ret[lernt] = *--str;
	return (ret);
}
