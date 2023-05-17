#include "main.h"

/**
 * parse_input - function is to parse the input string into separate tokens. 
 * @input: pointer to character.
 * @tokens: pointer to an array of pointers to characters (double pointer).
 * @tokens_num: pointer to integer
 * Return: 
*/

void parse_input(char* input, char** tokens, int* tokens_num) 
{
    char* token;
    char* a;

    a = " \t\n\r\a";
    *tokens_num = 0;
    token = strtok(input, a);

    while (token != NULL && *tokens_num < MAX_NUM_TOKENS) 
    {
        tokens[*tokens_num] = token;
        (*tokens_num)++;
        token = strtok(NULL, a);
    }
    tokens[*tokens_num] = NULL;
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