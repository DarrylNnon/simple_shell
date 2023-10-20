#include "shell.h"

/**
 * p_alias - is used to print an alias string
 * @node: the alias node
 * Return: as specified
 * builtin1.c
 */
int p_alias(list_t *node)
{
	char *q = NULL, *s = NULL;

	if (node)
	{
		q = strngStr(node->str, '=');
		s = node->str;
		while (s <= q)
		{
			put_caracter(*s);
			s++;
		}
		put_caracter('\'');
		putStrng(q + 1);
		putStrng("'\n");
		return (0);
	}
	return (1);
}
/**
 * _alias - is used to mimics the alias builtin
 * @info: Structure containing potential arguments.
 *  Return: as specified
 * builtin1.c
 */
int _alias(info_t *info)
{
	int j = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			p_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (j = 1; info->argv[j]; j++)
	{
		q = strngStr(info->argv[j], '=');
		if (q)
			s_alias(info, info->argv[j]);
		else
			p_alias(beginNodeWith(info->alias, info->argv[j], '='));
	}
	return (0);
}
