#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print - print a string
 * @str: pointer to string
*/
void _print(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}
}

/**
 * _strlen - calculate the length of a string.
 *
 * @s: the string to calculate it's length.
 * Return: length of a string.
 **/

int _strlen(char *s)
{
	int i;
	int x;

	x = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		x++;
	}
	return (x);
}
/**
 * _strcmp -  function that compares two strings.
 * @s1: first string.
 * @s2: second string.
 * Return: 0.
 */

int _strcmp(char *s1, char *s2)
{
	int res = 0;

	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	if (s1 != s2)
		res = *s1 - *s2;

	return (res);
}
