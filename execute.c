#include "shell.h"

/**
 * run_command - is the function to execute user input
 * @input: is the pointer to the string
 * Author: Nnon and Isaac
 */
int run_command(const char *input)
{
    char arg1[256], arg2[256], arg3[256];
    char *args[4];
    pid_t child_process;
    char command_path[256];

    sscanf(input, "%255s %255s %255s", arg1, arg2, arg3);

    args[0] = arg1;
    args[1] = arg2;
    args[2] = arg3;
    args[3] = NULL;

    if (strcmp(args[0], "setenv") == 0)
    {
        set_env(args);
        return (0);
    }
    else if (strcmp(args[0], "unsetenv") == 0)
    {
        unset_env(args);
        return (0);
    }


    snprintf(command_path, sizeof(command_path), "/bin/%s", args[0]);

    if (access(command_path, F_OK) != -1)
    {
        child_process = fork();

        if (child_process == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (child_process == 0)
        {
            execve(command_path, args, NULL);
            perror("execve");
            exit(EXIT_FAILURE);
        }
        else
        {
            signal(SIGINT, signal_handler);
            wait(NULL);
            signal(SIGINT, SIG_DFL);
        }
    }
    else
    {
        printit("Command does not exist\n", STDOUT_FILENO);
    }
    return (0);
}

