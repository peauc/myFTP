//
// Created by peau_c on 5/15/17.
//

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <server.h>

int send_accepted_response(t_client *client)
{
	const char * const welcomeMessage = "220\r\n";
	if (write(client->fd, welcomeMessage, strlen(welcomeMessage)) == -1) {
		dprintf(2, "Cannot write on socket, aborting\n");
		return (1);
	}
	return (0);
}
