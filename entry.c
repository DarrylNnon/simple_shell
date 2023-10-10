#include "shell.h"
#include <string.h>
/**
 * main - is the function used
 * Return: as specified
 * Author: Nnon and Isaac
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
        handle_arg(input, args);
        if (strcmp(args[0], "exit") == 0)
        {
            set_exit(args);
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

