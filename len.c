#include "main.h"

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
 * @s2: second chain.
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


/**
 * _verify -  verifies if haystack begins with needle.
 * @a: string to examine.
 * @b: the substring to locate.
 * Return: pointer to the following character after haystack or NULL.
 */
char *_verify(const char *a, const char *b)
{
	while (*b)
		if (*b++ != *a++)
			return (NULL);
	return ((char *)a);
}

/**
 * _strcat - a function that combines two strings.
 * @dest: a string.
 * @src: a string.
 * Return: a pointer to the resulting string dest.
 **/

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	return (dest);
}


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
