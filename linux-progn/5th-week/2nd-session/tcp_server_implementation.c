#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // 1. Create a TCP socket (IPv4, Stream, default protocol)
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure socket options to allow address reuse (prevents "Address already in use" errors)
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Configure the server address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Bind to all available interfaces
    address.sin_port = htons(PORT);       // Convert port to network byte order

    // 2. Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // 3. Listen for incoming connections (backlog of 3)
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d...\n", PORT);

    // 4. Accept a client connection
    if ((client_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Client connected successfully.\n");

    // 5. Implement Message Exchange Functionality (Bidirectional)
    while (1) {
        memset(buffer, 0, BUFFER_SIZE); // Clear buffer before reading
        
        // Receive message from client
        ssize_t bytes_read = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
        
        if (bytes_read > 0) {
            printf("Client: %s", buffer);
            
            // Prepare and send response back to client
            char response[BUFFER_SIZE + 50];
            snprintf(response, sizeof(response), "Server Acknowledges: %s", buffer);
            
            send(client_socket, response, strlen(response), 0);
        } else if (bytes_read == 0) {
            printf("Client disconnected normally.\n");
            break;
        } else {
            perror("Recv error");
            break;
        }
    }

    // Clean up file descriptors
    close(client_socket);
    close(server_fd);
    printf("Server shut down.\n");
    
    return 0;
}
