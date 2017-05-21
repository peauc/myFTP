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
#include <get_next_command.h>
#include "get_user_and_password.h"
#include "tools.h"
#include "command_handler.h"

int	server_logic_loop(t_client *client)
{
	t_command *ret;
	
	if (get_user_and_pass(client))
		return (1);
	while (client->shouldContinue)
	{
		if ((ret = get_next_command(client->fd)) == FATAL_ERROR)
		{
			dprintf_call(2, "%s-%d FatalError\n", __FUNCTION__, __LINE__);
			return (0);
		}
		else if (ret == SYNTAX_ERROR)
		{
			dprintf_call(2, "%s-%d SyntaxError\n", __FUNCTION__, __LINE__);
			continue ;
		}
		dprintf_call(2, "Normal execution\n");
		server_handle_command(ret, client);
	}
	if (close(client->fd) == -1)
	{
		dprintf_call(2, "Could not close client's fd\n");
		return (1);
	}
	return (0);
}
