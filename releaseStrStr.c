#include "shell.h"
/**
 * releaseStrStr - func frees str of strs
 * @pt: str of strs to be freed.
 * Return: returns void.
 * realloc.c
 */
void releaseStrStr(char **pt)
{
	char **a;

	a = pt;
	if (!pt)
		return;
	while (*pt)
	{
		free(*pt++);
	}
	free(a);
}
