#include "shell.h"
#include <string.h>

/**
 * handle_commands - is the function used to check cmd
 * @args: is the first pointer array for args
 * @input: is the pointer to string
 * Return: as specified
 * Authors: Nnon & Isaac
 */
void handle_commands(char *args[], char *input)
{
	int i = 0;

	if (strcmp(args[0], "exit") == 0)
	{
		set_exit(args[0];
	}
	else if (strcmp(args[0], "/bin/ls") == 0)
	{
		path_func(args);
	}
	else if (strcmp(args[0], "ls") == 0)
	{
		ls_exe(args);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		cd_command(args);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		env_command();
	}
	else if (strcmp(args[0], "setenv") == 0)
	{
		set_env(args);
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		unset_env(args);
	}
	else
	{
		run_command(input);
	}
	while (args[i] != NULL)
	{
		free(args[i]);
		args[i] = NULL;
		i++;
	}
}
/**
 * main - is the function to enter shell
 * Return: as specified
 */
int main(void)
{
	char input[100];
	char *args[100];

	while (1)
	{
		render_prompt();
		user_entry(input, sizeof(input));
		handle_args(input, args);

		if (args[0] != NULL)
		handle_commands(args, input);
	}
	return (0);
}

