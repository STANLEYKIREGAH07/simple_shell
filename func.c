#include "main.h"

/**
 * _e_exit - exit simple shell
 * @info: Container holding potential parameters.
 *  Return: exit.
 */
int _e_exit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_er(info, "Illegal number: ");
			print_str(info->argv[1]);
			print_char('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}


/**
 *_puts - outputs a given string.
 *@str: the string to be displayed.
 * Return: void.
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - outputs the character c to the standard output.
 * @c: The character to display.
 * Return: return 1 on success,
 * On failure, -1 is returned, and the errno is appropriately set.
 */
int _putchar(char c)
{
	static int i;
	static char a[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, a, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		a[i++] = c;
	return (1);
}

/**
 * free_s - free memory associated with a pointer
 * @ptr: free pointer.
 * Return: free return 1 else 0.
 */
int free_s(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

