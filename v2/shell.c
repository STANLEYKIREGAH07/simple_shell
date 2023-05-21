#include "main.h"
/*
 *main - reproduce the behavior of shell.
 * @argc: integer
 * @argv: double pointer
 * Return: output of sh
 **/


int main(int argc, char **argv)
{
	char *a;
	size_t a_size;
	ssize_t read;
	char *args[2];
	pid_t p;
	int status;
	(void)argc;
	(void)argv;
	a = NULL;
	a_size = 0;
	args[1] = NULL;
	while (1)
	{
		write(1, "#cisfun$ ", 9);
		read = getline(&a, &a_size, stdin);

		if (read == -1)
		{
			if (feof(stdin))
				break;
		}
		if (a[read - 1] == '\n')
		{
			a[read - 1] = '\0';
		}
		if (strcmp(a, "exit") == 0)
			break;
		args[0] = strtok(a, " ");
		p = fork();
		if (p <= 0)
		{
			execve(args[0], args, NULL);
			perror("./shell ");
			exit(1);
		}
		else
			wait(&status);
	}
	free(a);
	return (0);
}
