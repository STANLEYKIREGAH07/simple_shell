#include "shell.h"

/**
 * interactive - return true if shell is interactive
 * @info: struct address
 *
 * Return: 1 if interactive mode, otherwise 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks character is a delimeter
 * @c: the char to check
 * @delim: delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - check for alphabetic character
 * @c: character to input
 * Return: 1 if c is alphabetic,  otherwise 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - convert string to an integer
 * @s: string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int x, signn = 1, flagg = 0, outputt;
	unsigned int resultt = 0;
for (x = 0; s[x] != '\0' && flagg != 2; x++)
{
if (s[x] == '-')
signn *= -1;
if (s[x] >= '0' && s[x] <= '9')
{
flagg = 1;
resultt *= 10;
resultt += (s[x] - '0');
}
else if (flagg == 1)
flagg = 2;
}

	if (signn == -1)
		outputt = -resultt;
	else
		outputt = resultt;

	return (outputt);
}
