#include "main.h"

/**
 * not_found - write error "./shell: No such file or directory".
 * @str: typed command.
 * @c_n: The command typed by the  user.
 * @env: To write a shell script, incorporate a linked list of
 * environmental variables.
 */
void not_found(char *str, int c_n, list_t *env)
{
	int i;
	char *shell, *j;
	(void) str;

	shell = _access_env("_", env);

	i = 0;

	while (shell[i] != '\0')
		i++;

	write(STDOUT_FILENO, shell, i);

	free(shell);

	write(STDOUT_FILENO, ": ", 1);

	j = int_to_string(c_n);
	i = 0;
	while (j[i] != '\0')
		i++;
	write(STDOUT_FILENO, " No such file or directory\n", 27);
}


/**
 * error_nbr - write error.
 * @str: user's typed argument after the cmd exit
 * @c_n: The command typed by the  user.
 * @env: To write a shell script, incorporate a linked list of
 * environmental variables.
 */
void error_nbr(char *str, int c_n, list_t *env)
{
	int i;
	char *shell, *num;

	i = 0;
	shell = NULL;
	num = NULL;

	shell = _access_env("_", env);
	while (shell[i] != '\0')
		i++;
	write(STDOUT_FILENO, shell, i);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
	i = 0;
	while (num[i] != '\0')
		i++;
	write(STDOUT_FILENO, num, i);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number: ", 22);
	i = 0;
	while (str[i] != '\0')
		i++;
	write(STDOUT_FILENO, str, i);
	write(STDOUT_FILENO, "\n", 1);
}
