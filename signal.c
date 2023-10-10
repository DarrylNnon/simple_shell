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
    char *msg = "\n Cannot be terminated using Ctrl+C \n";
    int j = 0;

    signal(SIGINT, sigint_handler);
    while (msg[j] != '\0')
    {
        _putchar(msg[j]);
        j++;
    }
}

