/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/

#include <string.h>
#include <stdio.h>
#include "server.h"
#include "get_next_command.h"
#include "get_user_and_password.h"
#include "tools.h"

static t_command	*get_user(t_client *client)
{
	t_command	*user;
	
	if ((user = get_next_command(client->fd)) == FATAL_ERROR
		|| user == SYNTAX_ERROR)
		return (user);
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

static t_command	*get_pass(t_client *client)
{
	t_command	*pass;
	
	if ((pass = get_next_command(client->fd)) == FATAL_ERROR
		|| pass == SYNTAX_ERROR)
	{
		dprintf_call(2, "GetPass error %s\n", pass->arguments);
		return (pass);
	}
	if (pass->instruction != PASS)
	{
		send_wrong_user_pass_response(client);
		dprintf_call(2, "GetPass error %d %s\n", pass->instruction, pass->arguments);
		return (SYNTAX_ERROR);
	}
	dprintf_call(2, "GetPass working |%s|\n", pass->arguments);
	return (pass);
}

static void	handle_login(t_client *client, t_command *user, t_command *pass)
{
	dprintf_call(2, "|%s|\n|%s|\n", user->arguments, pass->arguments);
	if (strcmp(user->arguments, "Anonymous") == 0
		&& strcmp(pass->arguments, "") == 0)
	{
		dprintf_call(2, "Client is Logged\n");
		client->is_loged = true;
		send_good_login_response(client);
	}
	else
		send_wrong_login_response(client);
}

int	get_user_and_pass(t_client *client)
{
	int count;
	t_command *user;
	t_command *pass;
	
	count = 0;
	dprintf_call(2, "getUserAndPass\n");
	while (!client->is_loged)
	{
		if (count == MAXIMUM_TRY_PER_SESSION)
		    return (1);
		if ((user = get_user(client)) != SYNTAX_ERROR && user != FATAL_ERROR)
			if ((pass = get_pass(client)) != SYNTAX_ERROR && pass != FATAL_ERROR)
				handle_login(client, user, pass);
		count++;
	}
	return (0);
}
