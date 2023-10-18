#include <unistd.h>
#include <signal.h>
#include "shell.h"

/**
 * signal_handler - is used to accept signals
 * @sig_num: is the signal number
 * Author: Nnon and Isaac
 */
void signal_handler(int sig_num)
{
	char *msg;
	int j = 0;
	(void)sig_num;

	msg = "\n Cannot be terminated using Ctrl+C \n";

	signal(SIGINT, signal_handler);

	while (msg[j] != '\0')
	{
	_putchar(msg[j]);
	j++;
	}
}

