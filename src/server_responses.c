//
// Created by peau_c on 5/15/17.
//

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "server.h"
#include "tools.h"

int	send_wrong_login_order(t_client *client)
{
	return (write_on_socket(client->fd, "503 Login with USER first.\r\n"));
}


int	send_input_pass_response(t_client *client)
{
	return (write_on_socket(client->fd, "331 Please specify the password.\r\n"));
}

int	send_wrong_login_response(t_client *client)
{
	return (write_on_socket(client->fd, "530 Incorrect Login\r\n"));
}

int	send_wrong_user_pass_response(t_client *client)
{
	return (write_on_socket(client->fd, "530 Please login with USER and PASS.\r\n"));
}

int	send_accepted_response(t_client *client)
{
	return (write_on_socket(client->fd, "220 Welcome to peauc's awesome server\r\n"));
}
