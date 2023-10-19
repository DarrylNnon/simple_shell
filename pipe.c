#include "shell.h"
/**
 * parse_command - is function used to parse the command
 * @command: is the pointer to the command
 * @command1: is the pointer to the first command
 * @command2: is the pointer to the second command
 * Return: as specified
 */
int parse_command(char *command, char *command1, char *command2)
{
	char *pipe_symbol;

	pipe_symbol = strchr(command, '|');
	if (pipe_symbol == NULL)
	{
		fprintf(stderr, "Error: No pipe found.\n");
		return (-1);
	}
	if (pipe_symbol - command >= (long int)sizeof(command1))
	{
		fprintf(stderr, "Error: Command1 is too long.\n");
		return (-1);
	}
	strncpy(command1, command, pipe_symbol - command);
	command1[pipe_symbol - command] = '\0';
	if (strlen(pipe_symbol + 1) >= sizeof(command2))
	{
		fprintf(stderr, "Error: Command2 is too long.\n");
		return (-1);
	}
	strcpy(command2, pipe_symbol + 1);

	return (0);
}

/**
 * create_pipe - is function used to create a pipe
 * @pipefd: is the pointer to the pipe file descriptor
 * Return: as specified
 */
int create_pipe(int *pipefd)
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (-1);
	}

	return (0);
}

/**
 * handle_pipe - is function used to handle pipe cmd
 * @command: is the pointer to the command
 * Return: as specified
 */
void handle_pipe(char *command)
{
	char command1[256], command2[256];
	int pipefd[2];
	pid_t pid;

	if (parse_command(command, command1, command2) == -1)
	{
		return;
	}
	if (create_pipe(pipefd) == -1)
	{
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		run_command(command1);
		exit(EXIT_FAILURE);
	}
	else
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		run_command(command2);
	}
}

