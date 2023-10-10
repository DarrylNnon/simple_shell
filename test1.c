#include "shell.h"

void handle_argu(char *input, char **args)
{
	int i = 0;
	(void)*input;

	for (i = 0; args[i] != NULL; i++)
	{
    		free(args[i]);
	}
}

