#include "shell.h"

/**
 * custom_exit - is the func used to exit the shell
 * @info: Structure containing potential arguments.
 * Return: as specified
 * builtin.c
 */
int custom_exit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = error_atoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			error_print(info, "Illegal number: ");
			_puth(info->argv[1]);
			_putcar('\n');
			return (1);
		}
		info->err_num = error_atoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

