#include "shell.h"

void list_directory()
{
    int result = system("/bin/ls");
    
    if (result == -1)
    {
        perror("system");
    }
}
