//
// Created by ds on 07/10/23.
//

#ifndef CLIENT_H
#define CLIENT_H

int client(void);
void init_ncurses();
void end_ncurses();
void handle_server_message(char *message);
void send_movement_command(int key);

#endif    // SERVER_H
