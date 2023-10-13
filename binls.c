#include <stdio.h>
#include <unistd.h>

int path_func()
{
    char *cmd = "/bin/ls";
    char *argv[3];
    argv[0] = "ls";
    argv[1] = "-l";
    argv[2] = NULL;

    char *envp[] = { NULL };

    if (execve(cmd, argv, envp) < 0)
    {
        perror("execve");
        return 1;
    }

    return 0;
}

