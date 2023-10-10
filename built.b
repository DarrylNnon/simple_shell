#include "shell.h"

char *builtin_str[] = {"setenv", "unsetenv", "exit", "exitstatus", };

int (*builtin_func[]) (char **) = { &set_env, &unset_env, &exit, &exit_status, };

char *args[] = { "/bin/ls", "-l", "-a", NULL };
ls_exe(args);

