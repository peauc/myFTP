//
// Created by peau_c on 5/20/17.
//

#include "tools.h"
#include "server.h"

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

int	send_good_login_response(t_client *client)
{
	return (write_on_socket(client->fd, "230 Login successful.\r\n"));
}
