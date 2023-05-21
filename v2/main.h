#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 64

int _putchar(char c);
void _print(char *str);
int _strcmp(char *s1, char *s2);
void _prompt(void);
void out(char *input);
void execmd(char **arg);
void tokeninput(char *input, char **arg);
int _strlen(char *s);

#endif
