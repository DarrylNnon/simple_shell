#include "shell.h"
/**
 * run_command - is the function to execute user input
 * @input: is the pointer to the string
 * Author: Nnon and Isaac
 */
void run_command(const char *input)
{
    pid_t child_process = fork();

    if (child_process == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (child_process == 0)
    {
        char command_path[256];
        snprintf(command_path, sizeof(command_path), "/bin/%s", command);
        char *args[] = {command, NULL};
        execve(command_path, args, NULL);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }
}
