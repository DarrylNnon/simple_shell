#include "shell.h"

/**
 * copy_str - is used to copy string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@p: the amount of characters to be copied
 *Return: as specified
 */
char *copy_str(char *dest, char *src, int p)
{
	int a, b;
	char *q = dest;

	a = 0;
	while (src[a] != '\0' && a < p - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < p)
	{
		b = a;
		while (b < p)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (q);
}

/**
 **cat_str - is used to concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@p: the amount of bytes to be maximally used
 *Return: as specified
 */
char *cat_str(char *dest, char *src, int p)
{
	int a, b;
	char *q = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < p)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < p)
		dest[a] = '\0';
	return (q);
}
