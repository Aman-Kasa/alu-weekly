/*
Task:
1. Analyze the following code snippets.
2. Predict outputs before running.
3. Explain reasoning: pointer arithmetic vs array indexing.
4. Work in pairs and share predictions and logic with the class.
*///////////////////////////////////////////////////////////////////////
#include <stdio.h>

int main(void) {
    int arr[3] = {3, 5, 7};

    printf("%d\n", arr[1]);    // array indexing
    printf("%d\n", *(arr + 1)); // pointer arithmetic

    return 0;
}

