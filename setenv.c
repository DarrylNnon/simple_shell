#include "shell.h"

/**
 * _myenv - is used to print the current environment
 * @info: Structure containing potential arguments.
 * Return: as specified
 * environ.c
 */
int _myenv(info_t *info)
{
	prnt_lstStrng(info->env);
	return (0);
}

/**
 * get_env - is used to get the value of an env variable
 * @info: Structure containing potential arguments
 * @name: env variable name
 * Return: as specified
 */
char *get_env(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *q;

	while (node)
	{
		q = with_strt(node->str, name);
		if (q && *q)
		{
			return (q);
		}
		node = node->next;
	}
	return (NULL);
}
