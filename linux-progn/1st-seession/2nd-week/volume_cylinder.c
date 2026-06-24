#include <stdio.h>

// Global variable
double pi = 3.14159;

// Function 1: Square the radius
double square_radius(double r) {
    return r * r;
}

// Function 2: Multiply base area by height
double calculate_volume(double r_squared, double h) {
    return pi * r_squared * h;
}

// Function 3: Final output function
void print_output(double v) {
    printf("Volume: %.2f\n", v);
}

int main() {
    // 6 local variables
    double r = 5.0;
    double h = 10.0;
    double r_sq;
    double vol;
    int status = 0;
    int success = 1;

    r_sq = square_radius(r);
    vol = calculate_volume(r_sq, h);
    
    printf("Radius: %.2f, Height: %.2f\n", r, h);
    print_output(vol);
    
    return status;
}
