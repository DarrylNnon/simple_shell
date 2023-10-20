#include "shell.h"


/**
 * riplase_str - Replaces a string
 * @old: Address of the old string (pointer to a pointer).
 * @new: The new string to replace the old one.
 *
 * Return: 1 if successful, 0 otherwise.
 * vars.c
 */
int riplase_str(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
