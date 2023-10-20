#include "shell.h"
/**
 * s_alias - is used to set alias to str
 * @info: is a parameter to the struct
 * @str: the string alias
 * Return: as specified
 * builtin1.c
 */
int s_alias(info_t *info, char *str)
{
	char *i;

	i = strngStr(str, '=');
	if (!i)
		return (1);
	if (!*++i)
		return (u_alias(info, str));

	u_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
