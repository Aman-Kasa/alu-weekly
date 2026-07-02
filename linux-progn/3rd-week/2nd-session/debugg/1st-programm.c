#include <stdio.h>
int main() {
    FILE *fp = fopen("/nonexistent/file.txt", "r");
    if (!fp) perror("Error");
    return 0;
}
