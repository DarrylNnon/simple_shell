#include "shell.h"
#include <string.h>
#include <stdlib.h>

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
