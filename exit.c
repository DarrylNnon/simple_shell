#include "shell.h"
/**
 * set_exit - is the function to set builtin exit
 * @status: is the pointer to the array of arguments
 * Author: Nnon and Isaac
 */
void set_exit(char *status)
{
	int exit_status = 0;

	if (status != NULL)
	{
		exit_status = atoi(status);
	if (exit_status < 0 || exit_status > 255)
	{
		fprintf(stderr, "Exit status out of range\n");
		exit(EXIT_FAILURE);
	}
	}
	printu("Exiting with status %d\n", exit_status);
	exit(exit_status);
}

