#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <signal.h> // Required for fixing GAP 4

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    /* * [GAP 4: SIGNAL HANDLING FAILURE (SIGPIPE)]
     * FLAW: By default, if a client abruptly closes their connection, the 
     * kernel will kill this entire server the next time send() is called.
     * FIX: You must tell the OS to ignore SIGPIPE right here at the start, 
     * which forces send() to just return a -1 error instead of crashing.
     * Code to add: signal(SIGPIPE, SIG_IGN);
     */

    int server_fd, client_socket;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // 1. Create a TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Configure the server address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT);       

    // 2. Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // 3. Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d...\n", PORT);

    /*
     * [GAP 1: SINGLE-THREADED BLOCKING (NO CONCURRENCY)]
     * FLAW: execution completely halts on accept(). Once Client A connects, 
     * the code drops into the while(1) loop below and NEVER comes back up 
     * here to accept Client B. Client B will hang infinitely.
     * FIX: accept() needs to be inside a master loop, and the client_socket 
     * must be handed off to a new thread (pthreads), a new process (fork), 
     * or handled asynchronously (epoll).
     */
    if ((client_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Client connected successfully.\n");

    // 5. Message Exchange Loop (Only works for ONE client)
    while (1) {
        memset(buffer, 0, BUFFER_SIZE); 
        
        /*
         * [GAP 2: TCP STREAM FRAGMENTATION (NO FRAMING)]
         * FLAW: TCP is a continuous stream, not discrete messages. 
         * recv() just grabs whatever bytes happen to be in the hardware buffer 
         * right now. If a client sends 2000 bytes, this only grabs 1023, 
         * leaving the rest for the next loop. If a client sends 1 byte at a time, 
         * this fires 1023 times. 
         * FIX: Implement a protocol. The client must send a length header first 
         * (e.g., "0005HELLO"), and the server must loop recv() until exactly 5 
         * bytes are read.
         */
        ssize_t bytes_read = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
        
        if (bytes_read > 0) {
            /*
             * [GAP 3: BUFFER VULNERABILITIES & UNVALIDATED INPUT]
             * FLAW: We assume `buffer` contains nicely formatted text. 
             * If an attacker sends raw binary, or a payload without a null-terminator,
             * printf and snprintf can read out of bounds or trigger format string exploits.
             * FIX: Validate the bytes. Ensure they are printable characters or 
             * parse them safely (like a JSON struct) before ever pushing them into 
             * string manipulation functions.
             */
            printf("Client: %s", buffer);
            
            char response[BUFFER_SIZE + 50];
            snprintf(response, sizeof(response), "Server Acknowledges: %s", buffer);
            
            // Note: If the client disconnected just before this line, and GAP 4 
            // isn't fixed, this send() triggers SIGPIPE and kills the program.
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
