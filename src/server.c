//
// Created by peau_c on 5/12/17.
//

#include "server.h"

int server(char *path, unsigned short port)
{
	t_server server;
	
	server.path = path;
	server.port = port;
	if (server_init(&server))
		return (1);
	if (server_cleanup(&server))
		return (1);
	return (0);
}
