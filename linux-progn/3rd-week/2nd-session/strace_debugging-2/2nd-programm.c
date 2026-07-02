#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    for (int i = 0; i < 1000; i++) {
        int fd = open("/etc/passwd", O_RDONLY);
        if (fd > 0) {
            char buffer[100];
            read(fd, buffer, sizeof(buffer));
        }
    }
    return 0;
}
