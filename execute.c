#include "shell.h"
/**
 * run_command - is the function to execute user input
 * @input: is the pointer to the string
 * Return: as specified
 * Author: Nnon and Isaac
 */
int run_command(const char *input)
{
	char arg1[256], arg2[256], arg3[256];
	char *args[4];
	char command_path[256];

	int ret = sscanf(input, "%255s %255s %255s", arg1, arg2, arg3);

	args[0] = arg1;
	args[1] = arg2;
	args[2] = arg3;
	args[3] = NULL;

	if (ret != 3)
	{
		fprintf(stderr, "Error: could not read the expected number of items\n");
		return (-1);
	if (is_builtin(args))
	{
		execute_builtin(args);
		return (0);
	}
	snprintf(command_path, sizeof(command_path), "/bin/%s", args[0]);

	if (access(command_path, F_OK) != -1)
		execute_command(command_path, args);
	else
		printit("Command does not exist\n", STDOUT_FILENO);
	return (0);
}
/**
 * execute_builtin - executes a built-in command
 * @args: the arguments array
 */
void execute_builtin(char *args[])
{
	if (strcmp(args[0], "setenv") == 0)
		set_env(args);
	else if (strcmp(args[0], "unsetenv") == 0)
		unset_env(args);
}

