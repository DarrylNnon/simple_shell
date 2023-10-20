#include "shell.h"


/**
 * with_strt - Checks if the 'needle' starts with 'haystack'.
 * @haystack: The string to search within.
 * @needle: The substring to find at the beginning of 'haystack'.
 *
 * Return: A pointer to the address of the next character
 * string.c
 */
char *with_strt(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
		{
			return (NULL);
		}
	return ((char *)haystack);
}

/**
 * strncrtinasion - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 * string.c
 */
char *strncrtinasion(char *dest, char *src)
{
	char *rson;

	rson = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = *src;
	return (rson);
}
