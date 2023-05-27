#include "main.h"

/**
 **_mall - populates memory with a uniform byte value.
 *@a: the pointer to the memory block.
 *@b: the byte value to populate *ptr with.
 *@n: the number of bytes to populate.
 *Return: (ptr) a pointer to the populated memory block.
 */
char *_mall(char *a, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		a[i] = b;
	return (a);
}

/**
 * ffree - liberates a collection of character arrays.
 * @b: collection of character arrays.
 */
void ffree(char **b)
{
	char **a = b;

	if (!b)
		return;

	while (*b)
		free(*b++);
	free(a);
}

/**
 * _reloc - reallocates a chunk of memory.
 * @ptr: pointer to the previously allocated block.
 * @old_size: byte size of the previous block.
 * @new_size: byte size of the new block.
 * Return: pointer to the old block.
 */
void *_reloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	if (old_size < new_size)
	{
		old_size = old_size;
	}
	else
	{
		old_size = new_size;
	}

	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

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
