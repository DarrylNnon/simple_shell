#include "shell.h"

/**
 * custom_inte - is a function used for shell interactive mode
 * @info: struct address
 * Return: as specified
 * _atoic.c
 */
int custom_inte(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * delimiter - is func to check char is a delimeter
 * @i: the char being checked
 * @delimit: is the delimeter string
 * Return: as specified
 * _atoic.c
 */
int delimiter(char i, char *delimit)
{
	while (*delimit)
		if (*delimit++ == i)
			return (1);
	return (0);
}

