#include "shell.h"

/**
 * striinglent - Returns the length of a string.
 * @s: The string whose length to calculate.
 *
 * Return: An integer representing the length of the string.
 * string.c
 */
int striinglent(char *s)
{
	int x;

	if (s == NULL)
		return (0);

	for (x = 0; *s++; x++)
	;
	return (x);
}

/**
 * strrcompr - Performs a lexicographic comparison of two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: Negative if s1 < s2, positive if s1 > s2
 * string.c
 */

int strrcompr(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
		return (*s1 < *s2 ? -1 : 1);
}
