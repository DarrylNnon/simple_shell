#include "shell.h"
/**
 * run_cmd - is used to add char to cmds argu
 * @cmd: is the first pointer to arg
 * @op: is the second pointer to arg cmd
 * @num: is the number command input
 */
void run_cmd(char *cmd[MAX_COMMANDS], char *op[MAX_COMMANDS - 1], int num)
{
	int status = run_command(cmd[0]);
	int i = 1;

	while (i < num)
	{
		int and_condition = strcmp(op[i - 1], "&&") == 0 && status == 0;
		int or_condition = strcmp(op[i - 1], "||") == 0 && status != 0;

		if (and_condition || or_condition)
		{
			status = run_command(cmd[i]);
		}
	}
}
