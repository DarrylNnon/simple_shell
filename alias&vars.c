#include "shell.h"

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 * vars.c
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = beginNodeWith(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = strngStr(node->str, '=');
		if (!p)
			return (0);
		p = strnrwnp(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 * vars.c
 */
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!strrcompr(info->argv[i], "$?"))
		{
			riplase_str(&(info->argv[i]),
				strnrwnp(converter(info->status, 10, 0)));
			continue;
		}
		if (!strrcompr(info->argv[i], "$$"))
		{
			riplase_str(&(info->argv[i]),
				strnrwnp(converter(getpid(), 10, 0)));
			continue;
		}
		node = beginNodeWith(info->env, &info->argv[i][1], '=');
		if (node)
		{
			riplase_str(&(info->argv[i]),
				strnrwnp(strngStr(node->str, '=') + 1));
			continue;
		}
		riplase_str(&info->argv[i], strnrwnp(""));

	}
	return (0);
}
