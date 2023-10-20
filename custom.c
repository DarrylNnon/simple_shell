
#include "shell.h"

/**
 * show_history - displays the history list, one command by line
 * @info: is the pointer to the custom pointer
 *  Return: as specified
 * builtin1.c
 */
int show_history(info_t *info)
{
	dispList(info->history);
	return (0);
}

/**
 * u_alias - is used to set alias to string
 * @info: parameter of custom struct
 * @str: the string alias
 * Return: as specified
 * builtin1.c
 */
int u_alias(info_t *info, char *str)
{
	char *i, j;
	int rut;

	i = strngStr(str, '=');
	if (!i)
		return (1);
	j = *i;
	*i = 0;
	rut = dilitNodeIndex(&(info->alias),
		fetchIdx(info->alias, beginNodeWith(info->alias, str, -1)));
	*i = j;
	return (rut);
}

