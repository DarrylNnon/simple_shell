#include "shell.h"

/**
 * unset_env - function to unset builtin environment
 * @args: pointer to array of arguments
 * Return: as specified
 * Author: Nnon and Isaac
 */
int unset_env(char **args)
{
    if (args[1] == NULL)
    {
        printit("Usage: unsetenv VARIABLE\n", STDERR_FILENO);
        return (-1);
    }
    if (unsetenv(args[1]) == -1)
    {
        perror("unsetenv");
        return (-1);
    }
    return (0);
}

