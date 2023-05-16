#include "shell.h"

/**
 * _eputs - print input string
 * @str: string to print
 * Return: None
 */
void _eputs(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_eputchar(str[x]);
		x++;
	}
}

/**
 * _eputchar - write character c to stderr
 * @c: character to print
 * Return: 1 on success.
 * On error, return -1, and errno is appropriately set.
 */
int _eputchar(char c)
{
	static int x;
	static char buff[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buff, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buff[x++] = c;
	return (1);
}

/**
 * _putfd: write character c to fd
 * @c: character to print
 * @fd: filedescriptor to write to
 * Return: 1 on success.
 * On error, -1 is returned, and errno is appropriately set.
 */
int _putfd(char c, int fd)
{
	static int x;
	static char buff[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(fd, buff, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buff[x++] = c;
	return (1);
}

/**
 * _putsfd: print input string
 * @str: string to print
 * @fd: filedescriptor to write to
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int x = 0;

	if (!str)
		return (0);
	while (*str)
	{
		x += _putfd(*str++, fd);
	}
	return (x);
}
