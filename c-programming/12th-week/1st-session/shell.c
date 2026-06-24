#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    char input[100];
    char *args[10];
    
    while (1)
    {
        printf("myshell$ ");
        fgets(input, sizeof(input), stdin);

        /* Remove newline character */
        input[strcspn(input, "\n")] = '\0';

        /* Exit condition */
        if (strcmp(input, "exit") == 0)
            break;

        /* Tokenize input */
        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL)
        {
            i++;
            args[i] = strtok(NULL, " ");
        }

        pid_t pid = fork();   /* Create child */

        if (pid == 0)
        {
            /* CHILD PROCESS: execute command */
            execvp(args[0], args);
            perror("execvp failed");
            exit(1);
        }
        else
        {
            /* PARENT PROCESS: wait for child */
            wait(NULL);
        }
    }

    return 0;
}

