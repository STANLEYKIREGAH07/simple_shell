#include "main.h"

/**
 * _strcpy - copies the string pointed to by src into dest
 * @dest: destination
 * @src: source
 * Return: char with copy of string
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
 *_strdup - function that returns a pointer to a
 *newly allocated space in memory, which contains a copy
 *of the string given as a parameter.
 *@str: string
 *Return: pinter of an array of character
 **/

char *_strdup(char *str)
{
	char *strn;
	unsigned int i;
	int x;

	if (str == NULL)
		return (NULL);

	for (x = 0; str[x] != '\0'; x++)
		;
	strn = (char *)malloc(x + 1 * sizeof(char));
	if (strn != NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
			strn[i] = str[i];
	}
	else
		return (NULL);
	strn[i] = '\0';
	return (strn);
}


/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
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
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
