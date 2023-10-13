#include "shell.h"
#include <string.h>
/**
 * main - is the function used
 * Return: as specified
 * Authors: Nnon & Isaac
 */
int main(void)
{
    int i = 0;
    char input[100];
    char *args[100];

    while (1)
    {
        render_prompt();
        user_entry(input, sizeof(input));
        handle_args(input, args);
	
	if (strcmp(args[0], "exit") == 0)
        {
            set_exit(args);
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

     return 0;
}

