#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(void) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Step 2: Create socket using socket() system call
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port to prevent "Address already in use" errors
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Step 3: Set up server address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Step 4: Bind socket to address using bind()
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Step 5: Start listening with listen()
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", PORT);

    // Step 6: Accept connections in a loop
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
            perror("Accept failed");
            continue; // Keep the server running even if one accept fails
        }
        
        printf("Client connected.\n");

        // Step 7: Handle client communication (Echo)
        ssize_t valread;
        while ((valread = read(new_socket, buffer, BUFFER_SIZE - 1)) > 0) {
            buffer[valread] = '\0'; // Null-terminate the received string
            printf("Received: %s", buffer);
            
            // Echo back to client
            send(new_socket, buffer, valread, 0);
            memset(buffer, 0, BUFFER_SIZE); // Clear buffer for next read
        }

        if (valread == 0) {
            printf("Client disconnected.\n");
        } else if (valread < 0) {
            perror("Read error");
        }

        // Step 8: Clean up resources for this client
        close(new_socket);
    }

    // Unreachable in this infinite loop, but good practice
    close(server_fd);
    return 0;
}
