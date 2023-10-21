#include "shell.h"

/**
 * main_hsh - Main shell loop.
 * @input: The parameter and return information struct.
 * @ra: The argument vector from the main function.
 * Return: 0 on success, 1 on error, or an error code.
 */
int main_hsh(info_t *input, char **ra)
{
	int builtRet;
	ssize_t r;
	char *str = "";

	builtRet = 0;
	r = 0;
	while (r != -1 && builtRet != -2)
	{
		swappy(1, 0);
		clear_info(input);
		if (custom_inte(input))
			putStrng("Franklin_Isaac$$ ");
		_putcar(BUF_FLUSH);
		swappy(0, 1);
		r = write_input(input);
		if (r != -1)
		{
			half_print(str);
			set_info(input, ra);
			builtRet = fndBuiltiin(input);
			if (builtRet == -1)
				fnd_comd(input);
		}
		else if (custom_inte(input))
			put_caracter('\n');
		free_info(input, 0);
		half_print(str);
	}
	riteHistry(input);
	free_info(input, 1);
	if (!custom_inte(input) && input->status)
		exit(input->status);
	if (builtRet == -2)
	{
		if (input->err_num == -1)
			exit(input->status);
		exit(input->err_num);
	}
	half_print(str);
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
