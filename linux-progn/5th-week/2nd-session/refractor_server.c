#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <signal.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 100

// --- GLOBAL VARIABLES FOR THREAD SYNCHRONIZATION ---
int active_clients[MAX_CLIENTS];
int client_count = 0;

// Mutex lock to prevent race conditions when threads modify the client array
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER; 

// ---------------------------------------------------------
// Helper Function: Broadcast message to all active clients
// ---------------------------------------------------------
void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        // Optional: uncomment the if-statement if you don't want the sender to get their own message echoed back
        // if (active_clients[i] != sender_socket) {
            send(active_clients[i], message, strlen(message), 0);
        // }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// ---------------------------------------------------------
// THREAD 1: Listen to the Server Administrator's Keyboard
// ---------------------------------------------------------
void *server_input_thread(void *arg) {
    char input_buffer[BUFFER_SIZE];
    char formatted_msg[BUFFER_SIZE + 50];

    while (1) {
        // Wait for the server admin to type something
        if (fgets(input_buffer, BUFFER_SIZE, stdin) != NULL) {
            snprintf(formatted_msg, sizeof(formatted_msg), "[SERVER ADMIN]: %s", input_buffer);
            
            // Push the message to all connected clients
            broadcast_message(formatted_msg, -1); 
        }
    }
    return NULL;
}

// ---------------------------------------------------------
// THREAD 2: Handle Individual Client Traffic
// ---------------------------------------------------------
void *handle_client(void *socket_desc) {
    int client_sock = *(int*)socket_desc;
    char buffer[BUFFER_SIZE];
    free(socket_desc); 

    // Add this new client to our global array safely using mutex
    pthread_mutex_lock(&clients_mutex);
    if (client_count < MAX_CLIENTS) {
        active_clients[client_count++] = client_sock;
    }
    pthread_mutex_unlock(&clients_mutex);

    // Bidirectional message loop
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        ssize_t bytes_read = recv(client_sock, buffer, BUFFER_SIZE - 1, 0);
        
        if (bytes_read > 0) {
            printf("Client [Socket %d]: %s", client_sock, buffer);
            
            // Auto-acknowledge (You can remove this if you only want manual chatting)
            char response[BUFFER_SIZE + 50];
            snprintf(response, sizeof(response), "Server Acknowledges: %s", buffer);
            send(client_sock, response, strlen(response), 0);
            
        } else if (bytes_read == 0) {
            printf("Client [Socket %d] disconnected.\n", client_sock);
            break;
        } else {
            perror("Recv error");
            break;
        }
    }

    // Clean up: Remove client from the active array safely
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (active_clients[i] == client_sock) {
            // Shift array left to fill the gap
            for (int j = i; j < client_count - 1; j++) {
                active_clients[j] = active_clients[j + 1];
            }
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);

    close(client_sock);
    return NULL;
}

int main() {
    signal(SIGPIPE, SIG_IGN); // Prevent crashing on broken pipes

    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT);       

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Chat Server Online. Listening on port %d.\n", PORT);
    printf("Type a message here and press Enter to broadcast to all clients:\n");
    printf("--------------------------------------------------------------\n");

    // ---------------------------------------------------------
    // SPAWN THE SERVER INPUT THREAD
    // ---------------------------------------------------------
    pthread_t input_thread;
    if (pthread_create(&input_thread, NULL, server_input_thread, NULL) < 0) {
        perror("Failed to create server input thread");
        exit(EXIT_FAILURE);
    }
    // Detach so we don't have to join it later
    pthread_detach(input_thread);

    // ---------------------------------------------------------
    // THE MASTER CONNECTION LOOP
    // ---------------------------------------------------------
    while (1) {
        int *new_sock = malloc(sizeof(int));
        
        if ((*new_sock = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
            perror("Accept failed");
            free(new_sock);
            continue; 
        }
        
        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, handle_client, (void*)new_sock) < 0) {
            perror("Could not create thread");
            free(new_sock);
            continue;
        }
        pthread_detach(client_thread);
    }

    close(server_fd);
    return 0;
}
