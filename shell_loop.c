#include "main.h"

/**
 * main_sh - main shell loop
 * @info: the struct containing information about parameters,
 * and return values.
 * @av: the vector of arguments passed from the main() function
 * Return: 0 indicating successful execution, 1 indicating an error.
 **/

int main_sh(info_t *info, char **av)
{
	ssize_t i;
	int builtin_ret;

	i = 0;
	builtin_ret = 0;

	while (i != -1 && builtin_ret != -2)
	{
		_clear(info);
		if (interactive(info))
			_puts("#cisfun$ ");
		print_char(BUF_FLUSH);
		i = get_input(info);
		if (i != -1)
		{
			set_info(info, av);
			builtin_ret = find__cmd(info);
			if (builtin_ret == -1)
				see_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * find__cmd - search command.
 * @info: the information structure containing,
 * the parameter and return details.
 * Return: -1 in case the built-in command is not located,
 * 0 upon successful execution of the built-in command,
 * 1 if the built-in command is found but not successful,
 * -2 if the built-in command signals an exit().
 */
int find__cmd(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _e_exit},
		{"env", _myenv},
		{"setenv", _mysetenv},
		{"unsetenv", _rm_env},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * see_cmd - search command.
 * @info: the input and output data structure.
 * Return: void.
 */
void see_cmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = sear_p(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		exec_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_it_cmd(info, info->argv[0]))
			exec_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_er(info, "not found\n");
		}
	}
}

/**
 * exec_cmd - Spawns a new execution thread to execute the given command.
 * @info: the input and output data structure.
 * Return: void.
 */

void exec_cmd(info_t *info)
{
	pid_t p;

	p = fork();
	if (p == -1)
	{
		perror("Error:");
		return;
	}
	if (p == 0)
	{
		if (execve(info->path, info->argv, get_env(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_er(info, "Permission denied\n");
		}
	}
}
