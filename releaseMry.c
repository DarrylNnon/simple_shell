#include "shell.h"
/**
 * releaseMry - func releases a ptr.
 * @pointer: pointer to be freed
 * Return: returns 1 if success.
 * memory.c
 */
int releaseMry(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}
