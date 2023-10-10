#include "shell.h"
#include <string.h>
#include <stdlib.h>
/**
 * handle_args - parses the input string into an array of argument
 * @input: The input string to be parses.
 * @args: An array to store the parsed arguments.
 * Authors: Nnon & Isaac
 */
void handle_args(char *input, char **args)
{
    int i = 0, j = 0, k = 0;
    char arg[256];


    memset(arg, 0, sizeof(arg));

    while (1)
    {
        
        if (input[i] == ' ' || input[i] == '\0')
        {
            if (j > 0)
            {
                args[k] = strdup(arg);
                k++;
            }

       
            memset(arg, 0, sizeof(arg));
            j = 0;

            if (input[i] == '\0')
                break;
        }
        else
        {
            arg[j] = input[i];
            j++;
        }

        i++;
    }

    args[k] = NULL;
}
