#include "shell.h"
/**
 * handle_argu - Frees the memory allocated for arguments.
 * @input: The input string (not used in this function).
 * @args: An array of arguments to be freed.
 * Authors: Nnon & Isaac
 */
void handle_argu(char *input, char **args)
{
	int i = 0;
	(void)*input;

	for (i = 0; args[i] != NULL; i++)
	{
    		free(args[i]);
	}
}

