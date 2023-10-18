#include "shell.h"

void list_directory(void)
{
	int result = system("/bin/ls");

	if (result == -1)
	{
	perror("system");
	}
}
