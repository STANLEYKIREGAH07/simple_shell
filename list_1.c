#include "main.h"

/**
 * list_len - determines length of linked list.
 * @h: pointer to first node.
 * Return: size of list.
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * str_l - returns an array of strings of the list->str.
 * @head: pointer to first node.
 * Return: array of strings.
 */
char **str_l(list_t *head)
{
	list_t *node;
	size_t i, j;
	char **a;
	char *str;

	node = head;
	i = list_len(head);

	if (!head || !i)
		return (NULL);
	a = malloc(sizeof(char *) * (i + 1));
	if (!a)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(a[j]);
			free(a);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		a[i] = str;
	}
	a[i] = NULL;
	return (a);
}



/**
 * node__verify - returns node whose string starts with prefix.
 * @node: pointer to list head.
 * @prefix: string to match.
 * @c: the next character after prefix to match.
 * Return: match node or null.
 */
list_t *node__verify(list_t *node, char *prefix, char c)
{
	char *p;

	 p = NULL;

	while (node)
	{
		p = _verify(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

