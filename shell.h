#ifndef SIMPLE_H
#define SIMPLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int _putchar(char c);
void printit(char *string, int format);
int main(void);
void render_prompt(void);
void user_entry(char *input, size_t size);
void run_command(const char *input);
void token_input(char *input);
char *_getline(void);
char _getline(size_t *size);


#endif
