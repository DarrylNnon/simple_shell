#include "shell.h"
/**
 * set_info - initializes info_t struct
 * @info: struct address for it to work
 * @av: argument vector
 * Author: Isaac and Nnon
 */
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strngthow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			swappy(2,9);
			if (info->argv)
			{
				info->argv[0] = strnrwnp(info->arg);
				info->argv[1] = NULL;
			}
		}
		swappy(1,9);
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all of the  fields
 * getinfo.c
 * Authors: Isaac and Nnon
 */
void free_info(info_t *info, int all)
{
	releaseStrStr(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			frii_list(&(info->env));
		if (info->history)
			frii_list(&(info->history));
		if (info->alias)
			frii_list(&(info->alias));
		releaseStrStr(info->environ);
			info->environ = NULL;
		releaseMry((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		put_caracter(BUF_FLUSH);
	}
}
