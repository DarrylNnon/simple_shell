#include "shell.h"

#define MAX_CMD_LEN 256
#define PROMPT "($) "
/**
 * Enter the shell mode - allowing users to input command.
 * It read the command, processes it.
 * It's an interactive function
 * Authors: Nnon && Isaac
 */
int mode(void)
{
	char cmd[MAX_CMD_LEN];
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
	if (interactive)
	{
		write(STDOUT_FILENO, PROMPT, sizeof(PROMPT) - 1);
	}

	if (fgets(cmd, sizeof(cmd), stdin) == NULL)
	{
		break;
	}

	cmd[strcspn(cmd, "\n")] = '\0';

	if (strcmp(cmd, "exit") == 0)
	{
		break;
	}

	run_command(cmd);
	}

	return (0);
}

