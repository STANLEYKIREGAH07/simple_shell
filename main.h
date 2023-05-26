#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/**
 * struct list - linked list for environmental variables
 * @var: holds environmental variable string
 * @next: points to next node
 */
typedef struct list
{
	char *var;
	struct list *next;

} list_t;

/* function prototypes */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


char *_which(char *str, list_t *env);
int __exit(char **s, list_t *env, int num, char **command);
int _execve(char *argv[], list_t *env, int num);
void free_double_ptr(char **str);
void free_link_list(list_t *list);
int _env(char **str, list_t *env);
char *_access_env(char *str, list_t *env);
list_t *env_linked_list(char **env);
list_t *add_n_end(list_t **head, char *str);
size_t p_l(list_t *h);

int _unsetenv(list_t **env, char **str);
int _setenv(list_t **env, char **str);
int find_env(list_t *env, char *str);
void not_found(char *str, int num, list_t *env);

void error_nbr(char *str, int c_n, list_t *env);
char *int_to_string(int num);


int shell(char **env);
int _atoi(char *s);
void C_d(int i, char *command, list_t *env);
char *ign_space(char *str);
int built_in(char **token, list_t *env, int num, char **command);
void c_exit(char **str, list_t *env);
size_t get_line(char **str);
int t_strlen(char *str, int pos, char delm);
int t_size(char *str, char delm);
char *ignore_delm(char *str, char delm);
char **_str_tok(char *str, char *delm);
char **_str_c_tok(char *str, char *delm);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int c_t_size(char *str, char delm);
int numLength(int num);

#endif
