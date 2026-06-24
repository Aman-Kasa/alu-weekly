#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate a 2D matrix
int **allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Memory allocation failed for rows!\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed for columns!\n");
            exit(1);
        }
    }

    return matrix;
}

// Function to take user input for matrix
void inputMatrix(int **matrix, int rows, int cols) {
    printf("\nEnter scores for each player/team:\n");
    for (int i = 0; i < rows; i++) {
        printf("Player %d:\n", i + 1);
        for (int j = 0; j < cols; j++) {
            printf("  Round %d score: ", j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print matrix neatly
void printMatrix(int **matrix, int rows, int cols) {
    printf("\n--- Tournament Scoreboard ---\n");
    printf("      ");
    for (int j = 0; j < cols; j++) {
        printf("R%-4d", j + 1);
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        printf("P%-4d ", i + 1);
        for (int j = 0; j < cols; j++) {
            printf("%-5d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------\n");
}

// Function to free matrix memory
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to resize matrix (Extra feature)
int **resizeMatrix(int **matrix, int oldRows, int oldCols, int newRows, int newCols) {
    matrix = (int **)realloc(matrix, newRows * sizeof(int *));
    if (matrix == NULL) {
        printf("Reallocation failed for rows!\n");
        exit(1);
    }

    // Reallocate each row
    for (int i = 0; i < newRows; i++) {
        if (i < oldRows)
            matrix[i] = (int *)realloc(matrix[i], newCols * sizeof(int));
        else
            matrix[i] = (int *)malloc(newCols * sizeof(int));

        if (matrix[i] == NULL) {
            printf("Reallocation failed for row %d!\n", i);
            exit(1);
        }

        // Initialize new elements if any
        for (int j = oldCols; j < newCols; j++) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

// MAIN FUNCTION
int main() {
    int rows, cols;
    int **scores;

    printf("Enter number of players/teams: ");
    scanf("%d", &rows);
    printf("Enter number of rounds: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("Invalid dimensions!\n");
        return 1;
    }

    scores = allocateMatrix(rows, cols);
    inputMatrix(scores, rows, cols);
    printMatrix(scores, rows, cols);

    // Optional: Resize matrix
    char choice;
    printf("\nDo you want to resize the matrix? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        int newRows, newCols;
        printf("Enter new number of players: ");
        scanf("%d", &newRows);
        printf("Enter new number of rounds: ");
        scanf("%d", &newCols);

        scores = resizeMatrix(scores, rows, cols, newRows, newCols);
        printf("\nMatrix resized successfully!\n");

        // Optional: Fill new entries if needed
        printf("\nEnter new scores (or skip with 0):\n");
        inputMatrix(scores, newRows, newCols);

        printMatrix(scores, newRows, newCols);
        freeMatrix(scores, newRows);
    } else {
        freeMatrix(scores, rows);
    }

    printf("All memory freed. Program finished.\n");
    return 0;
}

