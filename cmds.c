#include "shell.h"
void run_commands(char *cmds[MAX_COMMANDS], char *ops[MAX_COMMANDS-1], int num_cmds)
{
    int status = run_command(cmds[0]);
    int i = 1;

    while (i < num_cmds)
    {
        if ((strcmp(ops[i-1], "&&") == 0 && status == 0) || (strcmp(ops[i-1], "||") == 0 && status != 0))
       	{
            status = run_command(cmds[i]);
        }
        i++;
    }
}

