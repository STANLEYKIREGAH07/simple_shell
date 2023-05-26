#include "main.h"

/**
 * interactive - returns true if the shell is in interactive mode.
 * @info: address structure.
 * Return: 1 if interactive mode, 0 otherwise.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - verifies whether the character acts as a separator.
 * @c: the character to validate.
 * @it: the string of separators.
 * Return: 1 if true, 0 if false.
 */
int is_delim(char c, char *it)
{
	while (*it)
		if (*it++ == c)
			return (1);
	return (0);
}

