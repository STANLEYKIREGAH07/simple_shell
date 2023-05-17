#include "main.h"

int main() {
    char input[MAX_INPUT_SIZE];
    char* tokens[MAX_NUM_TOKENS];
    int status;
    int i;
    ssize_t read_size;
    pid_t pid;

    while (1) 
    {
        printf("#cisfun$ ");
        
        fflush(stdout);
        read_size = read(STDIN_FILENO, input, MAX_INPUT_SIZE);
        
        if (read_size == 0) 
            break;

        if (_strcmp(input, "exit") == 0)
        {
            break;
            }

        parse_input(input, tokens, &i);

        pid = fork();

        if (pid <= 0) 
        {
            execve(tokens[0], tokens, NULL);
            perror("./shell");
            exit(1);
        } 
        else 
            wait(&status);
    
    }

    return 0;
}
