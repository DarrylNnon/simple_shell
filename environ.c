#include "shell.h"
/**
 * env_command: prints the environment variables
 * Authors: NNon & Isaac
 */
void env_command()
{
    char **env = environ;
    
    while (*env != NULL)
    {
        printit(*env, STDOUT_FILENO);
        printit("\n", STDOUT_FILENO);
        env++;
    }
}
