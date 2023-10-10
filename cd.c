#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cd_command(char **args)
{
    char *home_dir;
    char old_dir[256];
    char new_dir[256];


    getcwd(old_dir, sizeof(old_dir));

    if (args[1] == NULL || strcmp(args[1], "~") == 0)
    {    
        home_dir = getenv("HOME");
        if (home_dir != NULL)
       	{
            chdir(home_dir);
        }
       	else
       	{
            printf("cd: HOME not set\n");
        }
    }
    else if (strcmp(args[1], "-") == 0)
    {

        chdir(getenv("OLDPWD"));
    }
    else
    {
       
        if (chdir(args[1]) != 0)
       	{
            perror("cd");
        }
    }
   
    getcwd(new_dir, sizeof(new_dir));
    setenv("PWD", new_dir, 1);
    setenv("OLDPWD", old_dir, 1);
}

