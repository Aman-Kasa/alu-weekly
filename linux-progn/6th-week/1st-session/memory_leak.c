#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(100 * sizeof(int));

    char *str = malloc(50);
    free(str);

    printf("%s\n", str);

    return 0;
}
