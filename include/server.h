//
// Created by ds on 07/10/23.
//

#ifndef SERVER_H
#define SERVER_H

int server(void);
void initialize_server_socket();
void init_ncurses();
void end_ncurses();
void handle_client_input(int key);
void update_character_position(int x, int y);
void broadcast_character_position();
void handle_client_messages(int server_socket);


#endif    // SERVER_H
