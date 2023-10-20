#include "shell.h"

/**
 * populate_env_list - is used to populate env linked list
 * @info: Structure containing potential arguments
 * Return: as specified
 * environ.c
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	char **env_ptr = environ;

	while (*env_ptr)
	{
		add_node_end(&node, *env_ptr, 0);
		env_ptr++;
	}
	info->env = node;
	return (0);
}
