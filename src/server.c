//
// Created by peau_c on 5/12/17.
//

#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include "server.h"

int				server_core_loop(t_server *server)
{
	t_client	client;
	socklen_t	s_in_size;
	pid_t		fork_pid;
	
	s_in_size = sizeof(client.s_in_client);
	while (server->shouldStop)
	{
		client.fd = accept(server->fd, (struct sockaddr *) &client.s_in_client, &s_in_size);
		if (client.fd == -1)
		{
			dprintf(2, "Could not accept upcoming transmition\n");
			continue ;
		}
		fork_pid = fork();
		if (fork_pid == 0)
			if (server_logic_loop(server, &client))
				return (1);
	}
	return (0);
}
int server(char *path, unsigned short port)
{
	t_server server;
	
	server.path = path;
	server.port = port;
	if (server_init(&server))
		return (1);
	if (server_core_loop(&server))
		return (1);
	if (server_cleanup(&server))
		return (1);
	return (0);
}
