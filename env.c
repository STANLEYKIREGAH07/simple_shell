#include "main.h"


/**
 * _str_c - function that returns a pointer to a with little change.
 * @str: duplicate to be duplicated.
 * @k: byte number.
 * Return: string
 */
char *_str_c(char *str, int k)
{
	char *str_i;
	int i, len;

	if (str == NULL)
		return (NULL);

	len = 0;

	while (*(str + len))
		len++;
	len++;

	str_i = malloc(sizeof(char) * (len - k));

	if (str_i == NULL)
		return (NULL);

	i = 0;
	while (i < (len - k))
	{
		*(str_i + i) = *(str + k + i);
		i++;
	}
	return (str_i);
}

/**
 * _access_env - Retrieve and provide a duplicate of the specified
 * environmental variable.
 * @str: string variable to store it in.
 * @env: the complete collection of environmental variables.
 * Return: copy of requested environmental variable
 */

char *_access_env(char *str, list_t *env)
{
	int i, j;

	i = 0;
	j = i;

	while (env != NULL)
	{
		i = 0;
		while ((env->var)[i] == str[i])
			i++;
		if (str[i] == '\0' && (env->var)[i] == '=')
			break;
		env = env->next;
	}

	while (str[j] != '\0')
		j++;
	j++;
	return (_str_c(env->var, j));
}

