#include "shell.h"

int path_func()
{
	pid_t pid = fork();

	if (pid < 0)
	{
	perror("fork");
	return 1

	}

	else if (pid == 0)
	{

	char *cmd = "/bin/ls";
	char *envp[] = {"PATH=/usr/local/bin:/usr/bin:/bin", NULL};
	char *argv[] = {"ls", NULL};

	if (execve(cmd, argv, envp) < 0)
	{
	perror("execve");
	return 1;
	
	}

	}

	else
	{
	int status;
	waitpid(pid, &status, 0);
	}

	return 0;
}

