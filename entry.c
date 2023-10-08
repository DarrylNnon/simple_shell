#include "shell.h"
/**
 * main - is the function used
 * Return: as specified
 * Author: Nnon and Isaac
 */
int main(void)
{
    char input[100];

    while (1)
    {
        render_prompt();
        user_entry(input, sizeof(input));
        run_command(input);
    }

    return 0;
}

