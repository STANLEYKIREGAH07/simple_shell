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
	size_t input_s = 0;
	ssize_t read;
	pid_t p;
	int status;
	(void)argv;
	(void)argc;

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
			input[read - 1] = '\0';
		else
			input[read] = '\0';
		if (arg_count(input))
		{
			_print("./shell: No such file or directory\n");
			continue;
		}
		argv[0] = strtok(input, " ");
		p = fork();
		if (p <= 0)
		{
			execvp(argv[0], argv);
			perror("./shell ");
			exit(EXIT_SUCCESS);
		}
		else
			wait(&status);
	}
	free(input);
	return (0);
}
