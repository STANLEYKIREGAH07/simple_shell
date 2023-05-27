#include "main.h"

/**
 * rm__env - Remove an environment variable.
 * @info: Structure containing potential arguments.
 * @var: the string env var property.
 * Return: 1 on delete, 0 otherwise
 */
int rm__env(info_t *info, char *var)
{
	list_t *node;
	size_t i;
	char *p;

	i = 0;
	node = info->env;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = _verify(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = rm_node(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _env - returns the string array copy of our environ
 * @info: Structure containing potential arguments.
 * Return: 0
 */

char **_env(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = str_l(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}
/**
 * set_env - Initialize a new environment variable.
 * @info: Structure containing potential arguments.
 * @var: the string env var property.
 * @value: the string env var value.
 * Return: 0
 */
int set_env(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = _verify(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	_add_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
