#ifndef SIMPLE_H
#define SIMPLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>

#define MAX_COMMANDS 20

typedef struct Node
{
	char* data;
	struct Node* next;
} Node;

void run_commands(char *cmds[MAX_COMMANDS], char *ops[MAX_COMMANDS-1], int num_cmds);
void list_directory();
int path_func();
void printu(const char *format, ...);
Node* create_node(char* data);
Node* build_path_list();
void print_list(Node* head);
void ls_exe(char *args[]);
extern char **environ;
void signal_handler(int sig_num);
void env_command();
void printit(char *string, int format);
void _putchar(char c);
int main(void);
void render_prompt(void);
void user_entry(char *input, size_t size);
int run_command(const char *input);
void token_input(char *input);
char* _getline(size_t *size);
void cd_command(char **args);
void handle_argu(char *input, char **args);
void handle_args(char *input, char **args);
void handle_arg(char *input, char **args);
int set_env(char **args);
void set_exit(char *status);
int unset_env(char **args);
void handle_pipe(char *command);
int mode(void);
#endif
