//
// Created by peau_c on 5/12/17.
//

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <get_next_command.h>
#include "server.h"

static int get_user_and_pass(t_server *server, t_client *client)
{
	
	return (0);
}

int	server_logic_loop(t_server *server, t_client *client)
{
	(void) server;
	client->ip = inet_ntoa(client->s_in_client.sin_addr);
	get_user_and_pass(server, client);
	while (client->shouldContinue)
	{
		get_next_command();
	}
	if (close(client->fd) == -1)
	{
		dprintf(2, "Could not close client's fd\n");
		return (1);
	}
	return (0);
}
