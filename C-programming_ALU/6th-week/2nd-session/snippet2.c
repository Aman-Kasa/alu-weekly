/*//////////////////////////////////////////////////////////////
Task:
1. Analyze the following code snippets.
2. Predict outputs before running.
3. Explain reasoning: pointer arithmetic vs array indexing.
4. Work in pairs and share predictions and logic with the class.
*/////////////////////////////////////////////////////////////////

#include <stdio.h>

int main(void) {
    int arr[4] = {2, 4, 6, 8};
    int *ptr = arr;

    printf("%d\n", *(ptr + 2));  // pointer arithmetic

    return 0;
}

