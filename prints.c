#include "main.h"

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

/**
 * _put - outputs the character c to the specified fd.
 * @c: The character to display.
 * @b: The file descriptor to write to.
 * Return: Returns 1 on success,
 * On failure, it returns -1 and sets the appropriate errno value.
 */

int _put(char c, int b)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(b, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - displays an input string.
 * @str: the string to be showcased.
 * @b: the file descriptor to write into.
 * Return: the count of characters displayed.
 */
int _putsfd(char *str, int b)
{
	int i;

	i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _put(*str++, b);
	}
	return (i);
}
