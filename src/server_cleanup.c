//
// Created by peau_c on 5/12/17.
//

#include <stdio.h>
#include <unistd.h>
#include "server.h"
#include "tools.h"

int server_cleanup(t_server *server)
{
	if (close(server->fd) == -1)
	{
		dprintf_call(2, "Can't close the socket inside the cleanup\n");
		return (1);
	}
	return (0);
}
