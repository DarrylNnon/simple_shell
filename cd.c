#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * cd_command - change the current working directory based on the provided arguments
 * @args: An array of arguments for the cd command.
 * Authors: Nnon & Isaac
 */
void cd_command(char **args)
{
    char *home_dir;
    char old_dir[256];
    char new_dir[256];

    if (getcwd(old_dir, sizeof(old_dir)) == NULL)
    {
        perror("getcwd");
        return;
    }

    if (args[1] == NULL || strcmp(args[1], "~") == 0)
    {
        home_dir = getenv("HOME");
        if (home_dir != NULL)
        {
            if (chdir(home_dir) != 0)
            {
                perror("cd");
                return;
            }
        }
        else
        {
            printf("cd: HOME not set\n");
            return;
        }
    }
    else if (strcmp(args[1], "-") == 0)
    {
        char *oldpwd = getenv("OLDPWD");
        if (oldpwd != NULL)
        {
            if (chdir(oldpwd) != 0)
            {
                perror("cd");
                return;
            }
        }
        else
        {
            printf("cd: OLDPWD not set\n");
            return;
        }
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("cd");
            return;
        }
    }

    if (getcwd(new_dir, sizeof(new_dir)) == NULL)
    {
        perror("getcwd");
        return;
    }

    if (setenv("PWD", new_dir, 1) != 0 || setenv("OLDPWD", old_dir, 1) != 0)
    {
        perror("setenv");
        return;
    }
}

