#include "main.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter.
 * @info: the parameter struct.
 * @buf: the char buffer.
 * @p: address of current position in buf.
 * Return: 1 if chain delimeter, 0 otherwise.
 */

int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t i;

	i = *p;

	if (buf[i] == '|' && buf[i + 1] == '|')
	{
		buf[i] = 0;
		i++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[i] == '&' && buf[i + 1] == '&')
	{
		buf[i] = 0;
		i++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[i] == ';')
	{
		buf[i] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = i;
	return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status.
 * @info: the parameter struct.
 * @buf: the char buffer.
 * @p: address of current position in buf.
 * @i: starting position in buf.
 * @len: length of buf.
 * Return: Void.
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j;

	j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * change_a - replaces an aliases in the tokenized string.
 * @info: the parameter struct.
 * Return: 1 if replaced, 0 otherwise.
 */

int change_a(info_t *info)
{
	int i;
	list_t *node;
	char *a;

	for (i = 0; i < 10; i++)
	{
		node = node__verify(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		a = _loc(node->str, '=');
		if (!a)
			return (0);
		a = _strdup(a + 1);
		if (!a)
			return (0);
		info->argv[0] = a;
	}
	return (1);
}

/**
 * re_var - replaces vars in the tokenized string.
 * @info: the parameter struct.
 * Return: 1 if replaced, 0 otherwise.
 */

int re_var(info_t *info)
{
	int i;
	list_t *b;

	i = 0;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			re_str(&(info->argv[i]),
				_strdup(conv_nbr(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			re_str(&(info->argv[i]),
				_strdup(conv_nbr(getpid(), 10, 0)));
			continue;
		}
		b = node__verify(info->env, &info->argv[i][1], '=');
		if (b)
		{
			re_str(&(info->argv[i]),
				_strdup(_loc(b->str, '=') + 1));
			continue;
		}
		re_str(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * re_str - replaces string.
 * @old: address of old string.
 * @new: new string.
 * Return: 1 if success.
 */
int re_str(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
