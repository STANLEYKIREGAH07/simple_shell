#include "main.h"

/**
 * _strcpy - copies the string pointed to by src into dest.
 * @dest: destination.
 * @src: source.
 * Return: char with copy of string.
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	if (dest == src || src == 0)
		return (dest);
	for (i = 0; *(src + i) != '\0'; i++)
	{
		dest[i] = *(src + i);
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - creates a copy of a string.
 * @str: the string to be copied.
 * Return: pointer to the copied string.
 */

char *_strdup(const char *str)
{
	int length;
	char *a;

	length = 0;

	if (str == NULL)
		return (NULL);

	while (*str++)
		length++;

	a = malloc(sizeof(char) * (length + 1));

	if (!a)
		return (NULL);

	for (length++; length--;)
		a[length] = *--str;
	return (a);
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
