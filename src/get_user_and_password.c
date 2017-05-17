//
// Created by peau_c on 5/16/17.
//

#include <string.h>
#include <stdio.h>
#include "server.h"
#include "get_next_command.h"
#include "get_user_and_password.h"
#include "tools.h"

static t_command *get_user(t_client *client)
{
	t_command	*user;
	
	dprintf_call(2, "GetUser\n");
	if ((user = get_next_command(client->fd)) == FATAL_ERROR
		|| user == SYNTAX_ERROR)
		return ((int) user);
	if (user->instruction == PASS)
	{
		send_wrong_login_order(client);
		return (SYNTAX_ERROR);
	}
	else if (user->instruction != USER)
	{
		send_wrong_user_pass_response(client);
		return (SYNTAX_ERROR);
	}
	send_input_pass_response(client);
	return (user);
}

static t_command *get_pass(t_client *client)
{
	t_command	*pass;
	
	dprintf_call(2, "GetPass\n");
	if ((pass = get_next_command(client->fd)) == FATAL_ERROR
		|| pass == SYNTAX_ERROR)
		return ((int) pass);
	if (pass->instruction != PASS)
	{
		send_wrong_user_pass_response(client);
		return (SYNTAX_ERROR);
	}
	return (pass);
}

static void handle_login(t_client *client, t_command *user, t_command *pass)
{
	if (strcmp(user->arguments, "Anonymous") == 0 && strcmp(pass->arguments, "") == 0)
		client->is_loged = true;
	else
		send_wrong_login_response(client);
}
int get_user_and_pass(t_client *client)
{
	t_command *user;
	t_command *pass;
	
	dprintf_call(2, "getUserAndPass\n");
	user = get_user(client);
	pass = get_pass(client);
	handle_login(client, user, pass);
	return (0);
}
