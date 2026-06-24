// sample.c
#include <stdio.h>

int global_var = 42;
static int static_var = 10;

void my_function() {
    printf("Hello from function!\n");
}

int main() {
    my_function();
    return 0;
}
   
