//
// Created by peau_c on 5/12/17.
//

#ifndef MYFTP_SERVER_H
#define MYFTP_SERVER_H

#define QUEUE_SIZE		42

#include <netinet/in.h>
#include <stdbool.h>

typedef struct			s_server
{
	int					fd;
	unsigned short		port;
	char				*path;
	bool				shouldStop;
}						t_server;

typedef struct			s_client
{
	int					fd;
	char 				*ip;
	struct sockaddr_in	s_in_client;
	bool				shouldContinue;
	bool				is_loged;
}						t_client;

// ##############################################################################
// # SERVER.c																	#
// ##############################################################################
int						server(char *, unsigned short);

// ##############################################################################
// # SERVER_INIT.c																#
// ##############################################################################
int						server_init(t_server *server);

// ##############################################################################
// # SERVER_CLEANUP.c															#
// ##############################################################################
int						server_cleanup(t_server *server);

// ##############################################################################
// # SERVER_RESPONSES.c															#
// ##############################################################################
int						send_accepted_response(t_client *client);
int						send_wrong_user_pass_response(t_client *client);
int						send_wrong_login_response(t_client *client);
int						send_input_pass_response(t_client *client);
int						send_wrong_login_order(t_client *client);


// ##############################################################################
// # SERVER_LOGIC.c																#
// ##############################################################################
int						server_logic_loop(t_server *server, t_client *client);


#endif //MYFTP_SERVER_H
