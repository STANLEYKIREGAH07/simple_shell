#include "main.h"

/**
 * shell - UNIX command line interpreter.
 * @en: variables envirement.
 * Return: 0 in success
 */
int shell(char **en)
{
	list_t *env;
	size_t i, n;
	int input_line_nbr, exit_stat;
	char *cmd, *cmd_nbr, **token;

	input_line_nbr = 0;
	exit_stat = input_line_nbr;

	env = env_linked_list(en);
	while (1)
	{
		input_line_nbr++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		cmd = NULL;
		i = 0;
		i = get_line(&cmd);
		C_d(i, cmd, env);
		cmd_nbr = cmd;
		cmd = ign_space(cmd);
		n = 0;
		while (cmd[n] != '\n')
			n++;
		cmd[n] = '\0';
		if (cmd[0] == '\0')
		{
			free(cmd_nbr);
			continue;
		}
		token = NULL;
		token = _str_tok(cmd, " ");
		if (cmd_nbr != NULL)
			free(cmd_nbr);
		exit_stat = built_in(token, env, input_line_nbr, NULL);
		if (exit_stat)
			continue;
		exit_stat = _execve(token, env, input_line_nbr);
	}
	return (exit_stat);
}
