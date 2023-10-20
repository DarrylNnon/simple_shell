#include "shell.h"
/**
 * envUnset - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 * getenv.c
 */
int envUnset(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t x = 0;
	char *ptr;

	if (!node || !var)
	{
		return (0);
	}

	while (node)
	{
		ptr = with_strt(node->str, var);
		if (ptr && *ptr == '=')
		{
			info->env_changed = dilitNodeIndex(&(info->env), x);
			x = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		x++;
	}
	return (info->env_changed);
}

/**
 * setCustmEnv - is use to initialize a new environment variable,
 * @info: Structure containing potential arguments. Used to maintain
 * @var: the string env var property
 * @value: the string env var value
 *  Return: as specified
 * getenv.c
 */
int setCustmEnv(info_t *info, char *var, char *value)
{
	char *buffa = NULL;
	list_t *node;
	char *ptr;

	if (!var || !value)
		return (0);

	buffa = malloc(striinglent(var) + striinglent(value) + 2);
	if (!buffa)
		return (1);
	strncoppi(buffa, var);
	strncrtinasion(buffa, "=");
	strncrtinasion(buffa, value);
	node = info->env;
	while (node)
	{
		ptr = with_strt(node->str, var);
		if (ptr && *ptr == '=')
		{
			free(node->str);
			node->str = buffa;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buffa, 0);
	free(buffa);
	info->env_changed = 1;
	return (0);
}
