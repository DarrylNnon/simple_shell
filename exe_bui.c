#include "shell.h"
/**
 * is_builtin - checks if a command is a built-in
 * @args: the arguments array
 * Return: 1 if true, 0 if false
 */
int is_builtin(char *args[])
{
	if (strcmp(args[0], "setenv") == 0 || strcmp(args[0], "unsetenv") == 0)
	{
		return (1);
	}
	return (0);
}
/**
 * execute_command - executes a non-built-in command
 * @command_path: the path of the command
 * @args: the arguments array
 */
void execute_command(char *command_path, char *args[])
{
	pid_t child_process;

	child_process = fork();
	if (child_process == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_process == 0)
	{
		execve(command_path, args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		signal(SIGINT, signal_handler);
		wait(NULL);
		signal(SIGINT, SIG_DFL);
	}
}
