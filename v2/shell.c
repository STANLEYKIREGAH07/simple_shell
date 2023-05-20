#include "main.h"


int main(int argc, char **argv) 
{
    char *a;
    size_t a_size;

    (void)argc;(void)argv;

    a = NULL;
    a_size = 0;

    while (1) 
    {
        write(1,"#cisfun$ ",9);
        ssize_t read = getline(&a, &a_size, stdin);

        if (read == -1) 
        {
            if (feof(stdin)) 
            {
                printf("\n");
                break;
            } else {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        if (a[read - 1] == '\n') {
            a[read - 1] = '\0';
        }
        if (strcmp(a, "exit") == 0) 
        {
            break;
        }

        char *args[2];
        args[0] = strtok(a, " ");
        args[1] = NULL;

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            if (execve(args[0], args, NULL) == -1) {
                perror("./shell ");
                exit(EXIT_FAILURE);
            }
        } else {
            int status;
            if (wait(&status) == -1) 
            {
                perror("wait");
                exit(EXIT_FAILURE);
            }
        }
    }

    free(a);
    return 0;
}
