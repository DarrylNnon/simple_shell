#include "shell.h"
/**
 * user_entry - is the function to accept user entry
 * @input: is the pointer to the string
 * Author: Nnon and Isaac
 */
void user_entry(char *input, size_t size)
{
    if (fgets(input, size, stdin) == NULL)
    {
        if (feof(stdin))
	{
            printit("\n");
            exit(EXIT_SUCCESS);
        }
	else
	{
            perror("fgets");
            exit(EXIT_FAILURE);
        }
    }
    input[strcspn(input, "\n")] = '\0';
}