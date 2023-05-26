#include "main.h"

/**
 * add_n_end - add a node to the end of a linked list.
 * @head: pointer to head of linked list.
 * @str: data to new node.
 * Return: pointer to new linked list.
 */

list_t *add_n_end(list_t **head, char *str)
{
	list_t *n, *wait;

	if (head == NULL || str == NULL)
		return (NULL);

	n = malloc(sizeof(list_t));

	if (n == NULL)
		return (NULL);

	n->var = _strdup(str);
	n->next = NULL;

	wait = *head;
	if (wait != NULL)
	{
		while (wait->next != NULL)
		{
			wait = wait->next;
		}
		wait->next = n;
	}
	else
	{
		*head = n;
	}
	return (*head);
}

/**
 * p_l - print linked list.
 * @h: linked list.
 * Return: size of linked list.
 */
size_t p_l(list_t *h)
{
	list_t *c_list = h;
	int i, j;

	if (h == NULL)
		return (0);

	for (i = 0; c_list != NULL; i++)
	{
		if (c_list->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			for (j = 0; (c_list->var)[j] != '\0'; j++)
			{
			write(STDOUT_FILENO, c_list->var, j);
			write(STDOUT_FILENO, "\n", 1);
			}
		}
		c_list = c_list->next;
	}

	return (i);
}

/**
 * free_link_list - frees linked list
 * @list: linked list
 */
void free_link_list(list_t *list)
{
	list_t *holder;

	while (list != NULL)
	{
		holder = list;
		list = list->next;
		free(holder->var);
		free(holder);
	}

}

