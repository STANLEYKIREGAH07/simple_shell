#include "main.h"

/**
 * main - 
 * ac:int
 * argv: double pointer
 * Return: output of sh
 **/

int main(int ac, char **argv)
{
	char *a = "#cisfun$ ";
	char *b, *b1, *token;
	size_t i;
	ssize_t j;
	const char *d;
	int k, l;

	(void)ac;

	i = 0;
	d = "\n";
	b = NULL;
	b1 = b;
	k = i;
	l = i;

    while(1)
    {
        printf("%s", a);
        j = getline(&b, &i, stdin);
        b1 = malloc(sizeof(char) * j);
        if (j == -1)
            return (-1);
        if (b1 == NULL)
            return (-1);

        strcpy(b1, b);

        token = strtok(b, d);

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

    free(b);
    free(b1);
    return (0);
}
