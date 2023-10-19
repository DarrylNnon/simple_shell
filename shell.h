#ifndef SIMPLE_H
#define SIMPLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>

#define MAX_COMMANDS 20
/**
 *  struct Node - is the custom linked list
 *  @data: is the character pointer
 *  @next: is the second pointer value
 */
typedef struct Node
{
	char *data;
	struct Node *next;
} Node;

typedef struct env_list
{
	char *name;
	char *value;
	struct env_list *next;
} env_list_t;

int _cd(char **argv, env_list_t **env);
void execute_command(char *command_path, char *args[]);
void execute_builtin(char *args[]);
int is_builtin(char *args[]);
void run_cmd(char *cmd[MAX_COMMANDS], char *op[MAX_COMMANDS - 1], int num);
void list_directory(void);
int path_func(char **args);
void printu(const char *format, ...);
Node *create_node(char *data);
Node *build_path_list(void);
void print_list(Node *head);
void ls_exe(char *args[]);
extern char **environ;
void signal_handler(int sig_num);
void env_command(void);
void printit(char *string, int format);
void _putchar(char c);
int main(void);
void render_prompt(void);
void user_entry(char *input, size_t size);
int run_command(const char *input);
void token_input(char *input);
char *_getline(size_t *size);
void cd_command(char **args);
void handle_argu(char *input, char **args);
void handle_args(char *input, char **args);
void handle_arg(char *input, char **args);
int set_env(char **args);
void set_exit(char *status);
int unset_env(char **args);
int parse_command(char *command, char *command1, char *command2);
int create_pipe(int *pipefd);
void handle_pipe(char *command);
int mode(void);
#endif
