#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void token_input(char *input)
{
    char *token;
    char *delim = " ";

    token = strtok(input, delim);

    while (token != NULL)
    {
        printit("Token: %s\n", token);
        token = strtok(NULL, delim);
    }
}

