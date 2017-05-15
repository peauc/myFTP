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

int send_accepted_connection(t_client *client)
{
	const char * const welcomeMessage = "220\r\n";
	if (write(client->fd, welcomeMessage, strlen(welcomeMessage)) == -1) {
		dprintf(2, "Cannot write on socket, aborting\n");
		return (1);
	}
	return (0);
}
int server_logic_loop(t_server *server, t_client *client) {
		if (send_accepted_connection(client))
			return (1);
		client->ip = inet_ntoa(client->s_in_client.sin_addr);
		while (client->shouldContinue)
		{
			get_next_command();
			if (close(client->fd) == -1)
			{
				dprintf(2, "Could not close client's fd\n");
				return (1);
			}
		}
		return(0);
}
