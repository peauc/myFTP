//
// Created by peau_c on 5/12/17.
//

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <get_next_command.h>
#include "get_user_and_password.h"
#include "server.h"

int	server_logic_loop(t_client *client)
{
	t_command *ret;
	
	client->ip = inet_ntoa(client->s_in_client.sin_addr);
	get_user_and_pass(client);
	while (client->shouldContinue)
	{
		if ((ret = get_next_command(client->fd)) == FATAL_ERROR)
		{
			dprintf(2, "%s-%d FatalError\n", __FUNCTION__, __LINE__);
			return (0);
		}
		else if (ret == SYNTAX_ERROR)
		{
			dprintf(2, "%s-%d SyntaxError\n", __FUNCTION__, __LINE__);
			continue ;
		}
		dprintf(2, "Normal execution\n");
	}
	if (close(client->fd) == -1)
	{
		dprintf(2, "Could not close client's fd\n");
		return (1);
	}
	return (0);
}
