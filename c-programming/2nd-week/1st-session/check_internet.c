#include <stdio.h>
#include <stdlib.h>

int main() {
    int status;

    // Ping Google's DNS once
    status = system("ping -c 1 -W 2 8.8.8.8 > /dev/null 2>&1");

    if (status == 0) {
        printf("Connected\n");
    } else {
        printf("Disconnected\n");
    }

    return 0;
}
