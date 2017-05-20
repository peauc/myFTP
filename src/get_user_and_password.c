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
	
	//dprintf_call(2, "GetUser\n");
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
	
	if ((pass = get_next_command(client->fd)) == FATAL_ERROR
		|| pass == SYNTAX_ERROR)
	{
		dprintf_call(2, "GetPass error %s\n", pass->arguments);
		return ((int) pass);
	}
	if (pass->instruction != PASS)
	{
		send_wrong_user_pass_response(client);
		return (SYNTAX_ERROR);
	}
	dprintf_call(2, "GetPass working |%s|\n", pass->arguments);
	return (pass);
}

static void handle_login(t_client *client, t_command *user, t_command *pass)
{
	printf("|%s|\n|%s|\n", user->arguments, pass->arguments);
	if (strcmp(user->arguments, "Anonymous") == 0 && strcmp(pass->arguments, "") == 0)
	{
		dprintf_call(2, "Client is Logged\n");
		client->is_loged = true;
		send_good_login_response(client);
	}
	else
		send_wrong_login_response(client);
}

int get_user_and_pass(t_client *client)
{
	t_command *user;
	t_command *pass;
	
	dprintf_call(2, "getUserAndPass\n");
	while (!client->is_loged)
	{
		//TODO:CHECK SERVER CLIENT ACCESS
		if ((user = get_user(client)) != SYNTAX_ERROR && user != FATAL_ERROR)
			if ((pass = get_pass(client)) != SYNTAX_ERROR && pass != FATAL_ERROR)
				handle_login(client, user, pass);
	}
	return (0);
}
