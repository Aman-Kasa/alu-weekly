#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Task://///////////////////////////////////////////////////////////////////////

in pairs, write a C program that:
1.Reads 'n'names from the user.
2.Allocates memory dynamically using malloc().
3.Stores and prints the names.
4 Properly frees the allocated memory.

Peer Review: Explainyour code toone anotherin
yourgroupand then present asagroup *///////////////////////////////////////////////


int main() {
    int n;

    printf("Enter the number of names: ");
    scanf("%d", &n);
    getchar(); // consume newline after number input

    ////// Allocate memory for n pointers to strings
    char **names = (char **)malloc(n * sizeof(char *));
    if (names == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {

    	    ///// Allocate memory for each name (max 100 characters)
        names[i] = (char *)malloc(100 * sizeof(char));
        if (names[i] == NULL) {
            printf("Memory allocation failed for name %d!\n", i+1);
    
    	    /////// Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(names[j]);
            }
            free(names);
            return 1;
        }

        printf("Enter name %d: ", i + 1);
        fgets(names[i], 100, stdin);

        /////// Remove newline character if present
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    /////// Print all names
    printf("\nYou entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    //////// Free all allocated memory
    for (int i = 0; i < n; i++) {
        free(names[i]);
    }
    free(names);

    return 0;
}

