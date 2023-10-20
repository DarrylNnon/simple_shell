#include "shell.h"
/**
 * cd_command - is used to change the cd of process
 * @info: Structure containing potential arguments.
 *  Return: as specified
 * builtin.c
 */
int cd_command(info_t *info)
{
	char *j, *direc, buff[1024];
	int _chdir;

	j = getcwd(buff, 1024);
	if (!j)
		putStrng("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		direc = get_env(info, "HOME=");
		if (!direc)
			_chdir = /* TODO: what should this be? */
				chdir((direc = get_env(info, "PWD=")) ? direc : "/");
		else
			_chdir = chdir(direc);
	}
	else if (strrcompr(info->argv[1], "-") == 0)
	{
		if (!get_env(info, "OLDPWD="))
		{
			putStrng(j);
			put_caracter('\n');
			return (1);
		}
		putStrng(get_env(info, "OLDPWD=")), put_caracter('\n');
		_chdir = /* TODO: what should this be? */
			chdir((direc = get_env(info, "OLDPWD=")) ? direc : "/");
	}
	else
		_chdir = chdir(info->argv[1]);
	if (_chdir == -1)
	{
		error_print(info, "can't cd to ");
		_puth(info->argv[1]), _putcar('\n');
	}
	else
	{
		setCustmEnv(info, "OLDPWD", get_env(info, "PWD="));
		setCustmEnv(info, "PWD", getcwd(buff, 1024));
	}
	return (0);
}

/**
 * help_func - is the func that changes the cd of process
 * @info: Structure containing potential arguments.
 * Return: as specified
 * builtin.c
 */
int help_func(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	putStrng("help call works. Function not yet implemented \n");
	if (0)
		putStrng(*arg_array);
	return (0);
}
