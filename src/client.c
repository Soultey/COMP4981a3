#include "../include/client.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <ncurses.h>


int client(void) {
    // Initialize ncurses for character display and input handling
    init_ncurses();

    // Initialize client socket and other necessary variables
    // ...

    // Main loop
    while (1) {
        // Handle incoming server messages
        // ...

        // Send movement commands based on user input
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

void end_ncurses() {
    // End ncurses
    endwin();
}

void handle_server_message(char *message) {
    // Handle incoming messages from the server
    // Update character position accordingly
}

void send_movement_command(int key) {
    // Send movement command to the server based on user input
}

