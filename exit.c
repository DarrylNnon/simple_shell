#include "shell.h"
/**
 * set_exit - is the function to set builtin exit
 * @args: is the pointer to the array of arguments
 * Author: Nnon and Isaac
 */
void set_exit(char **args)
{
    int status = 0;

    if (args[1] != NULL)
    {
        status = atoi(args[1]);
        if (status < 0 || status > 255)
        {
            printit("Exit status out of range\n", STDERR_FILENO);
            return;
        }
    }
    exit(status);
}


