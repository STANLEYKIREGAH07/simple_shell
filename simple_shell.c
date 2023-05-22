#include "main.h"
/**
 * main - reproduce the behavior of shell.
 * @argc: integer
 * @argv: double pointer
 * Return: output of sh
 **/

int main(int argc, char **argv)
{
	char *input = NULL;
	char *arg[MAX_ARGS];
	size_t input_s = 0;
	ssize_t read;
	pid_t p;
	int status;
	(void)argc;
	(void)argv;

	while (1)
	{
		_prompt();
		read = getline(&input, &input_s, stdin);

		if (read == -1)
		{
			if (feof(stdin))
				break;
		}
		if (input[read - 1] == '\n')
		{
			input[read - 1] = '\0';
		}

		tokeninput(input, arg);
		out(input);
		p = fork();
		if (p == -1)
		{
			perror("./shell");
			exit(1);
		}
		else if (p == 0)
			execmd(arg);
		else
			wait(&status);
	}
	free(input);
	return (0);
}
