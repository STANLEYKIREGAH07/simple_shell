#ifndef MAIN_H
#define MAIN_H

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


#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
#define USE_GETLINE 0
#define USE_STRTOK 0

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
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
 *struct passinfo - comprises of mock arguments to transmit to a function.
 *@arg: sequence produced by getline encompassing parameters.
 *@argc: the count of arguments.
 *@argv: an array of strings derived from arg.
 *@path:  a string representing the current command's path.
 *@line_count: the count of errors.
 *@err_num: the exit() error code.
 *@linecount_flag: if enabled, count this input line.
 *@fname: the filename of the program.
 *@env: local copy of the environ linked list.
 *@environ: modified copy of environ from the LL env.
 *@history: the node representing the command history.
 *@alias: the node representing the command alias.
 *@env_changed: on if environ has been modified.
 *@status: the return status of the last executed command.
 *@cmd_buf: address of pointer to cmd_buf, on if chaining.
 *@cmd_buf_type: CMD_type indicating ||, &&, or ;
 *@readfd: the file descriptor used for reading line input
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	int argc;
	char *path;
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
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
} info_t;

#define INFO_INIT \
{NULL, NULL, 0, NULL, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0}

/**
 *struct builtin - includes an integrated string and associated operation.
 *@type: builtin command.
 *@func: function.
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/*each file and the function in it*/

/* func.c */
int _e_exit(info_t *);
int free_s(void **);
ssize_t read_buf(info_t *info, char *buf, size_t *i);
void _puts(char *);
int _putchar(char);

/* get_line.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* get_i.c */
void _clear(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);


/* get_env.c */
char **get_env(info_t *);
int _unsetenv(info_t *, char *);
int set_env(info_t *, char *, char *);

/* list.c */
list_t *_add_end(list_t **, const char *, int);
size_t _print_str_list(const list_t *);
int rm_node(list_t **, unsigned int);
void _list_free(list_t **);

/* list_1.c */
size_t list_len(const list_t *);
char **str_l(list_t *);
list_t *node__verify(list_t *, char *, char);

/* shell_env.c */
int main_sh(info_t *, char **);
int find__cmd(info_t *);
void see_cmd(info_t *);
void exec_cmd(info_t *);
char *_strdup(const char *);

/* er.c */
int _erratoi(char *);
void print_er(info_t *, char *);
int p_dec(int, int);
char *conv_nbr(long int, int, int);
void rm_c(char *);

/* len.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *_verify(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);

/* variable.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int change_a(info_t *);
int re_var(info_t *);
int re_str(char **, char *);

/* ex_cmd.c */
int is_it_cmd(info_t *, char *);
char *dup_char(char *, int, int);
char *sear_p(info_t *, char *, char *);
void print_str(char *);
int print_char(char);

/* environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _rm_env(info_t *);
int populate_env_list(info_t *);

/* exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_loc(char *, char);
char **strtow(char *, char *);
char **strtow1(char *, char);

/* _reloc.c */
char *_mall(char *, char, unsigned int);
void ffree(char **);
void *_reloc(void *, unsigned int, unsigned int);
int interactive(info_t *);
int is_delim(char, char *);
#endif
