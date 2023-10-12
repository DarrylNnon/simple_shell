#include "shell.h"

void handle_pipe(char *command)
{
    char command1[256], command2[256];
    char *pipe_symbol;

    int pipefd[2];
    pid_t pid;


    pipe_symbol = strchr(command, '|');
    if (pipe_symbol == NULL)
    {
        fprintf(stderr, "Error: No pipe found.\n");
        return;
    }

    if (pipe_symbol - command >= (long int)sizeof(command1))
    {
        fprintf(stderr, "Error: Command1 is too long.\n");
        return;
    }

    strncpy(command1, command, pipe_symbol - command);
    command1[pipe_symbol - command] = '\0';

    if (strlen(pipe_symbol + 1) >= sizeof(command2))
    {
        fprintf(stderr, "Error: Command2 is too long.\n");
        return;
    }

    strcpy(command2, pipe_symbol + 1);

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        return;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        run_command(command1);
        exit(EXIT_FAILURE);
    }
    else
    {
        
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[1]);
        run_command(command2);
    }
}

