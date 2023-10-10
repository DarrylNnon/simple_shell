#include "shell.h"
/**
 * handle_arg - is used to accept arguement
 * @input: is the pointer to the string
 * @args: is the double pointer to the string
 * Author: Nnon and Isaac
 */
void handle_arg(char *input, char **args)
{
    int i = 0, j = 0, k = 0;
    char *arg = malloc(strlen(input) + 1);

    while (1)
    {
        if (input[i] == ' ' || input[i] == '\0')
       	{
            arg[j] = '\0';
            args[k++] = strdup(arg);
            j = 0;
            if (input[i] == '\0')
		    break;
        }
       	else
       	{
            arg[j++] = input[i];
        }
        i++;
    }
    args[k] = NULL;
    free(arg);
}

