// server.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <ncurses.h>
#include "../include/server.h"


// Function prototypes

int server(const char *server_ip, int server_port){

    // Initialize server socket and other necessary variables
    initialize_server_socket(server_ip, server_port);

    // Initialize ncurses for character display and input handling
    init_ncurses();


    // Main loop
    while (1) {
        // Handle incoming client messages
        handle_client_messages(server_socket);

        // Update character position based on received messages
        // ...

        // Broadcast updated character position to all clients
        // ...
    }

    // Cleanup ncurses
    end_ncurses();

    return 0;
}

void init_ncurses() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}

int initialize_server_socket(const char *server_ip, int server_port)
 {
    // Initialize server socket and other necessary variables
    int server_socket;
    struct sockaddr_in server_addr;

    // Create UDP socket
    if ((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

        // Set socket options (if needed)
    // Example: Set socket timeout
    /*
    struct timeval timeout;
    timeout.tv_sec = 10; // 10-second timeout
    timeout.tv_usec = 0;
    if (setsockopt(server_socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    */

    // Set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);  // Listen on any available network interface
    server_addr.sin_port = htons(SERVER_PORT);       // Set server port

    // Bind socket to server address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    // Continue with server socket initialization as needed
}

void handle_client_messages(int server_socket) {
    // Buffer to store incoming message
    char buffer[1024];
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Receive message from client
    ssize_t bytes_received = recvfrom(server_socket, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &client_addr_len);
    if (bytes_received == -1) {
        perror("recvfrom");
        return;
    }

    // Process received message (e.g., update character position)
    // ...

    // Optional: Send response back to client if needed
    // ...
}

void end_ncurses() {
    // End ncurses
    endwin();
}

void handle_client_input(int key) {
    // Handle arrow key input from clients
    // Update character position accordingly
}

void update_character_position(int x, int y) {
    // Update character position on the server
}

void broadcast_character_position() {
    // Broadcast updated character position to all connected clients
}

