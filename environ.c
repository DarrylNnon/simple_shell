#include "shell.h"

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
