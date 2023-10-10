#include "shell.h"
#include <unistd.h>
#include <stdio.h>
/**
 * ls_exe - is used to call ls function
 * @args: is the double pointer to the args
 * Return: as specified
 * Author: Nnon and Isaac
 */
void ls_exe(char **args)
{
    char *envp[] = { NULL };
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        
        if (execve("/bin/ls", args, envp) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(NULL);
    }
}
