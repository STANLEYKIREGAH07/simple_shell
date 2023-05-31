#include "main.h"

/**
 * _myenv - displays the current environment.
 * @info: Structure holding possible parameters. Employed to uphold.
 * Return: 0
 */
int _myenv(info_t *info)
{
	_print_str_list(info->env);
	return (0);
}

/**
 * _getenv - retrieves the value of an environment variable.
 * @info: Structure containing possible arguments, utilized for maintenance.
 * @name: name of the environment variable.
 * Return: the retrieved value.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node;
	char *a;

	node = info->env;

	while (node)
	{
		a = _verify(node->str, name);
		if (a && *a)
			return (a);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv -  Create a fresh environment variable or update an existing one.
 * @info: Data structure containing possible arguments. Utilized to preserve.
 *  Return: 0.
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		print_str("Incorrect number of arguements\n");
		return (1);
	}
	if (set_env(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _rm_env - Delete an environment variable.
 * @info: Data structure holding possible arguments. Utilized for.
 *  Return: 0.
 */
int _rm_env(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		print_str("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		rm__env(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list -  fills env linked list
 * @info: Structure containing possible parameters. Used to preserve.
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node;
	size_t i;

	node = NULL;

	for (i = 0; environ[i]; i++)
		_add_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
