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
}						t_client;

// ##############################################################################
// # SERVER.c																	#
// ##############################################################################
int						server(char *, unsigned short);

// ##############################################################################
// # SERVER_INIT.c																#
// ##############################################################################
static int				bind_socket(int fd, unsigned short port);
static int				create_socket();
static int				listen_init(int fd);

int						server_init(t_server *server);

// ##############################################################################
// # SERVER_CLEANUP.c															#
// ##############################################################################
int						server_cleanup(t_server *server);

// ##############################################################################
// # SERVER_LOGIC.c																#
// ##############################################################################
int						server_logic_loop(t_server *server, t_client *client);


#endif //MYFTP_SERVER_H
