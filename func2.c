#include "main.h"

/**
 * C_d - exits program if Ctrl-D was pressed
 * @i: characters read via get_line
 * @command: user's typed in command
 * @env: environmental variable linked list
 */
void C_d(int i, char *command, list_t *env)
{
	if (i == 0)
	{
		free(command);
		free_link_list(env);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * ign_space - return string without spaces in front
 * @str: string
 * Return: new string
 */
char *ign_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * built_in - handles builtins (exit, env, cd)
 * @token: user's typed command
 * @env: environmental variable
 * @num: take in nth user command typed to write error message
 * @command: bring in command to free
 * Return: 1 if acted on builtin, 0 if not
 */
int built_in(char **token, list_t *env, int num, char **command)
{
	int i = 0;
	(void) num;
	(void) command;
	/**
	*if (_strcmp(token[0], "exit") == 0)
	*{
	*	i = _e_xit(token, env, num, command);
	*}
	**/
	if (_strcmp(token[0], "env") == 0)
	{
		_env(token, env);
		i = 1;
	}
	return (i);
}

/**
 * _e_xit - frees user input and then exits main program with a value
 * @str: user's command into shell
 * @env: bring in environmental variable to free at error
 * @num: bring in nth user command line input to print in error message
 * @command: bring in command to free
 * Return: 0 if success 2 if fail
 */
int _e_xit(char **str, list_t *env, int num, char **command)
{
	int e_value = 0;

	if (str[1] != NULL)
		e_value = _atoi(str[1]);

	if (e_value == -1)
	{
		error_nbr(str[1], num, env);
		free_double_ptr(str);
		return (2);
	}
	free_double_ptr(str);
	free_link_list(env);
	if (command != NULL)
		free_double_ptr(command);
	exit(e_value);
}

/**
 * c_exit - frees user's typed command and linked list before exiting
 * @str: user's typed command
 * @env: input the linked list of envirnment
 */
void c_exit(char **str, list_t *env)
{
	free_double_ptr(str);
	free_link_list(env);
	_exit(0);
}

