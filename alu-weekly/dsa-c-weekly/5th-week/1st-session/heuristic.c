#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a point on a 2D coordinate grid
typedef struct {
    int x;
    int y;
} Point;

// 1. Manhattan Distance (4-way orthogonal movement)
double get_manhattan_distance(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

// 2. Diagonal / Chebyshev Distance (8-way movement, uniform cost)
double get_diagonal_distance(Point p1, Point p2) {
    int dx = abs(p1.x - p2.x);
    int dy = abs(p1.y - p2.y);
    return (dx > dy) ? dx : dy;
}

// 3. Euclidean Distance (Straight line / continuous space)
double get_euclidean_distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt((dx * dx) + (dy * dy));
}

int main() {
    // Sample coordinates from the assignment slide
    Point start = {0, 0};
    Point goal = {3, 4};

    printf("=== Heuristic Distance Comparison ===\n");
    printf("Start Node: (%d, %d)\n", start.x, start.y);
    printf("Goal Node:  (%d, %d)\n\n", goal.x, goal.y);

    // Run calculations
    double manhattan = get_manhattan_distance(start, goal);
    double diagonal  = get_diagonal_distance(start, goal);
    double euclidean = get_euclidean_distance(start, goal);

    // Display formatted results
    printf("1. Manhattan Distance:  %.2f\n", manhattan);
    printf("2. Diagonal Distance:   %.2f\n", diagonal);
    printf("3. Euclidean Distance:  %.2f\n", euclidean);
    printf("=====================================\n");

    return 0;
}
