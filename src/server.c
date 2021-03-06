/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/

#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include "server.h"
#include "client_init.h"
#include "tools.h"

int		accept_new_connection(t_server *server, t_client *client)
{
	socklen_t	s_in_size;
	
	s_in_size = sizeof(client->s_in_client);
	client->fd = accept(server->fd,
						(struct sockaddr *) &client->s_in_client, &s_in_size);
	if (client->fd == -1)
	{
		dprintf_call(2, "Could not accept upcoming transmition\n");
		return (1);
	}
	if (send_accepted_response(client))
		return (1);
	return (0);
}

int				server_core_loop(t_server *server)
{
	t_client	client;
	pid_t		fork_pid;
	
	client_init(&client, server);
	while (!server->shouldStop)
	{
		if (accept_new_connection(server, &client))
			return (1);
		fork_pid = fork();
		if (fork_pid == 0)
		{
			client.ip = inet_ntoa(client.s_in_client.sin_addr);
			printf("[ENTR] Entering the server_logic_loop\n");
			if (server_logic_loop(&client))
				return (1);
			printf("[QUIT] Leaving the server_logic_loop\n");
			return (0);
		}
	}
	return (0);
}

int	server(char *path, unsigned short port)
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
