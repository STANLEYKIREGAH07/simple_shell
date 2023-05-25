#include"main.h"
/**
 * _prompt - print #cisfun$.
 * Return:  print #cisfun$.
*/

void _prompt(void)
{
	write(1, "#cisfun$ ", 9);
}
/**
 * tokeninput - check the input
 * @input:  pointer to char
 * @arg: double pointer to char
 * Return: void
 **/

void tokeninput(char *input, char **arg)
{
	char *token;
	int i;

	i = 0;
	token = strtok(input, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		arg[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	arg[i] = NULL;
}

/**
 * execmd - execute the command
 * @arg: double pointer to char
 * Return: command execution
*/

void execmd(char **arg)
{
	char *errormes;

	errormes = "./shell: No such file or directory\n";

	if (execve(arg[0], arg, NULL) == -1)
	{
		write(2, errormes, strlen(errormes));
		_exit(1);
	}
}

/**
 *out - Implement the exit built-in, that exits the shell
 *@input: pointer to char
 *Return: exit.
*/
void out(char *input)
{
	if (_strcmp(input, "exit") == 0)
	{
		exit(0);
	}
}



/**
 * arg_count - Check the number of arguments entered.
 * @input: Input string.
 * Return: 1 if the number of arguments is greater than 1, otherwise 0.
 **/
int arg_count(char *input)
{
	int argCo;
	char *arg;

	argCo = 0;
	arg = strtok(input, " ");

	while (arg != NULL)
	{
		argCo++;
		arg = strtok(NULL, " ");
	}

	if (argCo > 1)
		return (1);
	else
		return (0);
}

/**
 * getline - 
 * 
 * Return:
*/

