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
#include "tools.h"
#include "command_handler.h"

int	server_logic_loop(t_client *client)
{
	t_command *ret;
	
	get_user_and_pass(client);
	while (client->shouldContinue)
	{
		if ((ret = get_next_command(client->fd)) == FATAL_ERROR)
		{dprintf_call(2, "%s-%d FatalError\n", __FUNCTION__, __LINE__);return (0);}
		else if (ret == SYNTAX_ERROR)
		{dprintf_call(2, "%s-%d SyntaxError\n", __FUNCTION__, __LINE__);continue ;}
		dprintf_call(2, "Normal execution\n");
		server_handle_command(ret, client);
	}
	if (close(client->fd) == -1)
	{dprintf_call(2, "Could not close client's fd\n");return (1);}
	return (0);
}
