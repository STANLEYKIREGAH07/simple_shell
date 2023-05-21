#include"main.h"
/**
 * _prompt - print #cisfun$.
 * Return:  print #cisfun$.
*/

void _prompt(void)
{
	write(1, "#cisfun$ ", 9);
	fflush(stdout);
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

    if (execvp(arg[0], arg) == -1)
    {
        char *errormes = "./shell: No such file or directory\n";
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
