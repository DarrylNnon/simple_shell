#include "shell.h"

/**
  * _cd - change directory
  * @argv: argument vector
  * @env: environment linked list
  */
int _cd(char **argv, env_list_t **env)
{
	char buf[BUFSIZ];
	char *home = _getenv_list_value("HOME", env);
	char *old = _getenv_list_value("OLDPWD", env);
	char **OLDPWD = malloc(sizeof(char *) * 4);
	char **PWD = malloc(sizeof(char *) * 4);
	DIR *dir;

	OLDPWD[0] = "";
	OLDPWD[1] = "OLDPWD";
	OLDPWD[2] = buf;
	OLDPWD[3] = NULL;
	PWD[0] = "";
	PWD[1] = "PWD";
	PWD[2] = buf;
	PWD[3] = NULL;
	getcwd(buf, sizeof(buf));

	getcwd(old_dir, sizeof(old_dir));
	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
		home_dir = getenv("HOME");
		if (home_dir != NULL)
		{
			chdir(home_dir);
		}
		else
		{
			printu("cd: HOME not set\n");
		}
	}
	else if (strcmp(args[1], "-") == 0)
	{
		chdir(getenv("OLDPWD"));
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
	getcwd(new_dir, sizeof(new_dir));
	setenv("PWD", new_dir, 1);
	setenv("OLDPWD", old_dir, 1);
}

