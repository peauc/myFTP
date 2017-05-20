//
// Created by peau_c on 5/15/17.
//

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "server.h"
#include "tools.h"


int	send_accepted_response(t_client *client)
{
	return (write_on_socket(client->fd, "220 Welcome to peauc's awesome server\r\n"));
}
