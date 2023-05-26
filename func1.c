#include "main.h"

/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	int i;
	unsigned int num;

	i = 0;
	num = 0;

	while (s[i] != '\0')
	{
		if (s[i] > '9' || s[i] < '0')
			return (-1);
		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + (s[i] - '0');
		i++;
	}
	return (num);
}

/**
 * _strcat - function thar concatenantes two strings
 * @dest:string
 * @src:string
 *
 * Return: a pointer to the resulting string dest
 **/

char *_strcat(char *dest, char *src)
{
	int i, j, k;
	int t_len;

	t_len = 0;
	i = 0;
	j = i;
	k = j;

	while (dest[i] != '\0')
	{
		i++;
		t_len++;
	}
	while (src[k] != '\0')
	{
		k++;
		t_len++;
	}

	dest = _realloc(dest, i, sizeof(char) * t_len + 1);

	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * _strcmp -  function that compares two strings.
 * @s1: primera cadena.
 * @s2: segunda cadena.
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
 * _strcpy - copies the string pointed to by src into dest
 * @dest: destination
 * @src: source
 * Return: char with copy of string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

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
