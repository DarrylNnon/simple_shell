#include "shell.h"
/**
 * set_env - is the function to set builtin environment
 * @args: is the pointer to the array of arguments
 * Return: as specified
 * Author: Nnon and Isaac
 */
void set_env(char **args)
{
    if (args[1] == NULL || args[2] == NULL)
    {
        printit("Usage: setenv VARIABLE VALUE\n", STDERR_FILENO);
        return;
    }
    if (setenv(args[1], args[2], 1) == -1)
    {
        perror("setenv");
        return;
    }
}
