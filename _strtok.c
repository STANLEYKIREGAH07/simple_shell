#include "main.h"

/**
 * _str_tok - Split the string into tokens and provide
 * an array containing those tokens.
 * @str: Capture the command entered by the user in the shell.
 * @d: Use a specific delimiter for separation.
 * Return: A collection of tokens, represented as an array.
 */
char **_str_tok(char *str, char *d)
{
	char **toks, d_ch;
	int b_size = 0, p = 0, si = 0, i = 0, len, se = 0, t = 0;

	toks = NULL;

	d_ch = d[0];
	toks = malloc(sizeof(char *) * (b_size + 2));
	/**
	*str = ignore_delm(str, d_ch);
	**/
	b_size = t_size(str, d_ch);

	if (toks == NULL)
		return (NULL);
	while (str[se] != '\0')
		se++;
	while (si < se)
	{
		if (str[si] != d_ch)
		{
			len = t_strlen(str, si, d_ch);
			toks[p] = malloc(sizeof(char) * (len + 1));
			if (toks[p] == NULL)
				return (NULL);
			i = 0;
			while ((str[si] != d_ch) && (str[si] != '\0'))
			{
				toks[p][i] = str[si];
				i++;
				si++;
			}
			toks[p][i] = '\0';
			t++;
		}
		if (si < se && (str[si + 1] != d_ch && str[si + 1] != '\0'))
			p++;
		si++;
	}
	p++;
	toks[p] = NULL;
	return (toks);
}
