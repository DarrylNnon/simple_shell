#include "shell.h"
/**
 * _setenv - is used to initialize a new environment var
 * @info: Structure containing potential arguments.
 *  Return: as specified
 * environ.c
 */
int _setenv(info_t *info)
{
	if (info->argc != 3)
	{
		_puth("Incorrect number of arguements\n");
		return (1);
	}
	if (setCustmEnv(info, info->argv[1], info->argv[2]))
	{
		return (0);
	}
	return (1);
}

/**
 * un_setenv - is used to remove an environment var
 * @info: Structure containing potential arguments.
 *  Return: as specified
 * environ.c
 */
int un_setenv(info_t *info)
{
	int j;

	if (info->argc == 1)
	{
		_puth("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= info->argc; j++)
	{
		envUnset(info, info->argv[j]);
	}

	return (0);
}

