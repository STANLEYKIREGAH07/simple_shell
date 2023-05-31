#include "main.h"

/**
 * is_it_cmd - identifies whether a file functions as an executable directive.
 * @info: the data structure.
 * @path: file's location.
 * Return: 1 when accurate, 0 in any other case.
 */

int is_it_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;

	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_char - repeated characters.
 * @pathstr: the string representing the PATH.
 * @start: index where it starts.
 * @stop: index where it ends-
 * Return: reference to fresh memory allocation.
 */
char *dup_char(char *pathstr, int start, int stop)
{
	static char a[1024];
	int i, k;

	i = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			a[k++] = pathstr[i];
	a[k] = 0;
	return (a);
}

/**
 * sear_p - locates this command within the PATH string.
 * @info: the information structure.
 * @pathstr: the string that represents the PATH.
 * @cmd: the command to locate.
 * Return: complete path of the command if found or NULL.
 */
char *sear_p(info_t *info, char *pathstr, char *cmd)
{
	int i, c_position;
	char *a;

	i = 0;
	c_position = 0;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && _verify(cmd, "./"))
	{
		if (is_it_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			a = dup_char(pathstr, c_position, i);
			if (!*a)
				_strcat(a, cmd);
			else
			{
				_strcat(a, "/");
				_strcat(a, cmd);
			}
			if (is_it_cmd(info, a))
				return (a);
			if (!pathstr[i])
				break;
			c_position = i;
		}
		i++;
	}
	return (NULL);
}


/**
 *print_str - print string.
 * @str: string.
 * Return: void.
 */

void print_str(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		print_char(str[i]);
		i++;
	}
}

/**
 * print_char - print character.
 * @c: character.
 * Return: 1 if success and -1 in error.
 */

int print_char(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
