#include "shell.h"
/**
 * list_directory - is used to list available directory
 */
void list_directory(void)
{
	int result = system("/bin/ls");

	if (result == -1)
	{
	perror("system");
	}
}
