#include <unistd.h>
#include <stdio.h>
/**
 * ls_exe - is used to call ls function
 * @args: is the double pointer to the args
 * Author: Nnon and Isaac
 */
void ls_exe(char **args)
{
    char *envp[] = { NULL };

    if (execve("/bin/ls", args, envp) == -1)
    {
        perror("execve");
    }
}


