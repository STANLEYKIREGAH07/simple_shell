#include "main.h"

/**
 * cmd - function to check input
 *@argv: double pointer
 * Return: ./shell if there is a problem:
 **/

void cmd(char **argv)
{
	char *b;

	b = NULL;

	if (argv)
	{
		b = argv[0];

		if (execve(b, argv, NULL) == -1)
		{
			perror("./shell");
		}
	}
}
