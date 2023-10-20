#include "shell.h"


/**
 * fnd_comd - Finds and executes a command in PATH.
 * @info: The parameter and return information struct.
 *
 * Return: void.
 * shell_loop.c
 */
void fnd_comd(info_t *info)
{
	int x, k;
	char *path;

	path = NULL;
	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (x = 0, k = 0; info->arg[x]; x++)
		if (!delimiter(info->arg[x], " \t\n"))
			k++;
	if (!k)
		return;

	path = pthSearch(info, get_env(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		frrk_comd(info);
	}
	else
	{
		if ((custom_inte(info) || get_env(info, "PATH=")
			|| info->argv[0][0] == '/') && cmdExec(info, info->argv[0]))
			frrk_comd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			error_print(info, "not found\n");
		}
	}
}

/**
 * frrk_comd - Forks a child process
 * @info: return information struct.
 *
 * Return: void.
 * shell_loop.c
 */

void frrk_comd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				error_print(info, "Permission denied\n");
		}
	}
}
