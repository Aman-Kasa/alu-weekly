#include <stdio.h>
int main() {
    FILE *fp = fopen("/root/secret.txt", "w");
    if (!fp) perror("Permission denied");
    return 0;
}
