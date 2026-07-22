#include <stdio.h>
#include <stddef.h>

struct BadAlignment {
    char a;
    int b;
    char c;
    int d;
};

struct GoodAlignment {
    int b;
    int d;
    char a;
    char c;
};

int main() {
    printf("Size of BadAlignment: %zu bytes\n", sizeof(struct BadAlignment));
    printf("Size of GoodAlignment: %zu bytes\n", sizeof(struct GoodAlignment));

    printf("\nOffsets in BadAlignment:\n"); 
    printf("a: %zu\n", offsetof(struct BadAlignment, a));
    printf("b: %zu\n", offsetof(struct BadAlignment, b));
    printf("c: %zu\n", offsetof(struct BadAlignment, c));
    printf("d: %zu\n", offsetof(struct BadAlignment, d));
     
    printf("\nOffsets in GoodAlignment:\n");
    printf("b: %zu\n", offsetof(struct GoodAlignment, b));
    printf("d: %zu\n", offsetof(struct GoodAlignment, d));
    printf("a: %zu\n", offsetof(struct GoodAlignment, a));
    printf("c: %zu\n", offsetof(struct GoodAlignment, c));
    return 0;
}

