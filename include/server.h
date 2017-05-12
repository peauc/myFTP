//
// Created by peau_c on 5/12/17.
//

#ifndef MYFTP_SERVER_H
#define MYFTP_SERVER_H

#define QUEUE_SIZE	42

typedef struct		s_server
{
	int				fd;
	unsigned short	port;
	char			*path;
}					t_server;

// ##############################################################################
// # SERVER.c																	#
// ##############################################################################

int					server(char *, unsigned short);

// ##############################################################################
// # SERVER_INIT.c																#
// ##############################################################################
static int			bind_socket(int fd, unsigned short port);
static int			create_socket();
static int			listen_init(int fd);

int					server_init(t_server *server);

// ##############################################################################
// # SERVER_CLEANUP.c															#
// ##############################################################################
int					server_cleanup(t_server *server);

#endif //MYFTP_SERVER_H
