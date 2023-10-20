#include "shell.h"
/**
 * histryRenumba - Renumbers the history linked list after changes.
 * @info: Structure containing potential arguments.
 *
 * Return: The new histcount (the updated count of history entries).
 * history.c
 */
int histryRenumba(info_t *info)
{
	int x;
	list_t *node = info->history;

	x = 0;
	while (node)
	{
		node->num = x++;
		node = node->next;
	}
	return (info->histcount = x);
}
