#include "main.h"

/**
 * _realloc - Reserve memory and initialize all values to zero.
 * @ptr: Utilize a memory pointer referencing the previously allocated space.
 * @old_size: The size that was allocated earlier.
 * @new_size: Allocate memory for a new size.
 * Return: Utilize a pointer to access reallocated memory.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int k;
	void *j;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		j = malloc(new_size);
		if (j == NULL)
			return (NULL);
		else
			return (j);
	}

	j = malloc(new_size);
	if (j == NULL)
		return (NULL);

	for (k = 0; k < old_size && k < new_size; k++)
		*((char *)j + k) = *((char *)ptr + k);
	free(ptr);

	return (j);
}
