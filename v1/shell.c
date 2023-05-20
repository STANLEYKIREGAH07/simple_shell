#include "main.h"

/**
 * main - 
 * ac:int
 * argv: double pointer
 * Return: output of sh
 **/

int main(int ac, char **argv)
{
	char *b, *b1, *token;
    char input[MAX_INPUT_SIZE];
    char* tokens[MAX_NUM_TOKENS];
	size_t i;
	ssize_t j;
	const char *d;
	int k, l,m, n;
    pid_t p;

	(void)ac;

	i = 0;
	d = "\n";
	b = NULL;
	b1 = b;
	k = i;
	l = i;
    n =0 ;

    while(1)
    {
        write(1,"#cisfun$ ",9);
        j = getline(&b, &i, stdin);
        b1 = malloc(sizeof(char) * j);
        if (j == -1)
            return (-1);
        if (b1 == NULL)
            return (-1);
        i = read(STDIN_FILENO, j, MAX_INPUT_SIZE);
        fflush(stdout);

        if (i == n)
         break;
        if (_strcmp(j, "exit") == n)
            break;;

        parse_input(j, tokens, &m);

        p = fork();

        while (token != NULL)
        {
            k++;
            token = strtok(NULL, d);
        }
        k++;

        argv = malloc(sizeof(char *) * k);

        token = strtok(b1 ,d);

        for (l = 0; token != NULL; l++)
        {
            argv[l] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[l],token);

            token = strtok(NULL, d);
        }
        argv[l] = NULL;

        cmd(argv);
    }


    return (0);
}
