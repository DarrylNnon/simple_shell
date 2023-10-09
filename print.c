#include "shell.h"
#include <unistd.h>
/**
 * printit - is the function for printing output
 * @string: is the pointer to the string
 * @format: is the file descriptor
 * Author: Nnon and Isaac
 */
void printit(char *string, int format)
{
	int j = 0;

	while (string[j] != '\0')
	{
		write(format, &string[j], 1);
		j++;
	}
}
