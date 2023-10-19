#include "shell.h"
/**
 * token_input - is used to tokenize input
 * @input: is the pointer to user string
 * Author: Nnon and Isaac
 */
void token_input(char *input)
{
	int i = 0, j = 0, k = 0;
	char *arg = malloc(strlen(input) + 1);
	char **tokens = malloc((strlen(input) / 2 + 1) * sizeof(char *));

	while (1)
	{
	if (input[i] == ' ' || input[i] == '\0')
	{
		arg[j] = '\0';
		tokens[k++] = strdup(arg);
		j = 0;
		if (input[i] == '\0')
			break;
	}
	else
	{
		arg[j++] = input[i];
	}
	i++;
	}
	tokens[k] = NULL;

	for (i = 0; tokens[i] != NULL; i++)
	{
	printu("Token: %s\n", tokens[i]);
	free(tokens[i]);
	}
	free(tokens);
	free(arg);
}
