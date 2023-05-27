#include "main.h"



/**
 * set_info - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 * Return: void.
 */
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		change_a(info);
		re_var(info);
	}
}

/**
 * _clear - initializes info_t struct
 * @info: struct address
 * Return: void.
 */

void _clear(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * free_info - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 * Return: void.
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			_list_free(&(info->env));
		if (info->history)
			_list_free(&(info->history));
		if (info->alias)
			_list_free(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		free_s((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
