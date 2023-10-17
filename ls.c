#include "shell.h"
#include <sys/wait.h>

void ls_exe(char *args[])
{
    pid_t pid;
    (void)args;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        int result = system("/bin/ls");
        if (result == -1)
       	{
            perror("system");
            exit(EXIT_FAILURE);
        }
    } 
    else
    {
        wait(NULL);
    }
}

