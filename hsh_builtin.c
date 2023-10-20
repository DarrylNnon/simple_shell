#include "shell.h"

/**
 * main_hsh - Main shell loop.
 * @info: The parameter and return information struct.
 * @av: The argument vector from the main function.
 *
 * Return: 0 on success, 1 on error, or an error code.
 * shell_loop.c
 */
int main_hsh(info_t *info, char **av)
{
	int builtRet;
	ssize_t r;

	builtRet = 0;
	r = 0;
	while (r != -1 && builtRet != -2)
	{
		clear_info(info);
		if (custom_inte(info))
			putStrng("$ ");
		_putcar(BUF_FLUSH);
		r = write_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtRet = fndBuiltiin(info);
			if (builtRet == -1)
				fnd_comd(info);
		}
		else if (custom_inte(info))
			put_caracter('\n');
		free_info(info, 0);
	}
	riteHistry(info);
	free_info(info, 1);
	if (!custom_inte(info) && info->status)
		exit(info->status);
	if (builtRet == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtRet);
}

/**
 * fndBuiltiin - Finds a built-in command and executes it.
 * @info: The parameter and return information struct.
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 * shell_loop.c
 */
int fndBuiltiin(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", custom_exit},
		{"env", _myenv},
		{"help", help_func},
		{"history", show_history},
		{"setenv", _setenv},
		{"unsetenv", un_setenv},
		{"cd", cd_command},
		{"alias", _alias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (strrcompr(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}
