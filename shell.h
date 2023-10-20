#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number of field
 * @str: a string 
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 * Authors: Isaac and Nnon
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag for it to work
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* toem_shloop.c */
int main_hsh(info_t *, char **);
int fndBuiltiin(info_t *);
void fnd_comd(info_t *);
void frrk_comd(info_t *);

/* toem_parser.c */
int cmdExec(info_t *, char *);
char *chDuplicate(char *, int, int);
char *pthSearch(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
void _puth(char *);
int _putcar(char);
int in_puts(char a, int fd);
int _putin(char *input, int fd);

/* toem_string.c */
int striinglent(char *);
int strrcompr(char *, char *);
char *with_strt(const char *, const char *);
char *strncrtinasion(char *, char *);

/* toem_string1.c */
char *strncoppi(char *, char *);
char *strnrwnp(const char *);
void putStrng(char *);
int put_caracter(char);
ssize_t writeBuffa(info_t *, char **, size_t *len);
ssize_t input_buffa(info_t *info, char *buf, size_t *i);

/* toem_exits.c */
char *copy_str(char *, char *, int);
char *cat_str(char *, char *, int);
char *strngStr(char *, char);

/* toem_tokenizer.c */
char **strngthow(char *, char *);
char **strngthow2(char *, char);

/* toem_realloc.c */
char *fillMryWithByte(char *, char, unsigned int);
void releaseStrStr(char **);
void *chngAlloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int releaseMry(void **);

/* toem_atoi.c */
int custom_inte(info_t *info);
int delimiter(char i, char *delimit);
int alpha(int);
int custom_atoi(char *);
/* toem_errors1.c */
int error_atoi(char *);
void error_print(info_t *, char *);
int decimal_pr(int, int);
char *converter(long int, int, int);
void rem_comment(char *);

/* toem_builtin.c */
int custom_exit(info_t *);
int cd_command(info_t *);
int help_func(info_t *);

/* toem_builtin1.c */
int show_history(info_t *);
int _alias(info_t *);
int s_alias(info_t *info, char *str);
int u_alias(info_t *info, char *str);
/*toem_getline.c */
ssize_t write_input(info_t *);
int line_geta(info_t *, char **, size_t *);
void sign_handler(int);

/* toem_getinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* toem_environ.c */
char *get_env(info_t *, const char *);
int _myenv(info_t *);
int _setenv(info_t *);
int un_setenv(info_t *);
int populate_env_list(info_t *);

/* toem_getenv.c */
char **get_environ(info_t *);
int envUnset(info_t *, char *);
int setCustmEnv(info_t *, char *, char *);

/* toem_history.c */
char *getHstryFile(info_t *info);
int riteHistry(info_t *info);
int histry_riider(info_t *info);
int histry_list(info_t *info, char *buf, int linecount);
int histryRenumba(info_t *info);

/* toem_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t prnt_lstStrng(const list_t *);
int dilitNodeIndex(list_t **, unsigned int);
void frii_list(list_t **);

/* toem_lists1.c */
size_t listLen(const list_t *);
char **listStrs(list_t *);
size_t dispList(const list_t *);
list_t *beginNodeWith(list_t *, char *, char);
ssize_t fetchIdx(list_t *, list_t *);

/* toem_vars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int riplase_str(char **, char *);

#endif

