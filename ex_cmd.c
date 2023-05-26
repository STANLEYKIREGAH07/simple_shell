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
	char *path;

	i = 0;
	c_position = 0;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_it_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_char(pathstr, c_position, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_it_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			c_position = i;
		}
		i++;
	}
	return (NULL);
}
