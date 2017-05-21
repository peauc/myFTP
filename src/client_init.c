/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/

#include <netdb.h>
#include "tools.h"
#include "server.h"

int						create_new_data_socket(t_client *client)
{
	struct protoent		*pe;
	struct sockaddr_in	addr;
	socklen_t			socklen;
	
	pe = getprotobyname("TCP");
	if ((client->data_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
		return (1);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = 0;
	if (bind(client->data_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1)
		return (1);
	if (listen(client->data_fd, 1) == -1)
		return (1);
	socklen = sizeof(addr);
	if (getsockname(client->data_fd, (struct sockaddr*)&addr, &socklen) == -1)
		return (1);
	client->data_port = ntohs(addr.sin_port);
	return (0);
}

int		accept_connection_from_client(t_client *client)
{
	struct sockaddr_in sockaddr;
	int		tmp_size;
	int		new_socket;
	
	tmp_size = sizeof(sockaddr);
	new_socket = accept(client->data_fd,
						(struct sockaddr*)&sockaddr, (socklen_t*)(&tmp_size));
	if (new_socket < 0)
	{
		dprintf_call(2, "Cannot accept from the client\n");
		return (1);
	}
	return (new_socket);
}

int		client_init(t_client *client, t_server *server)
{
	client->data_fd = -1;
	client->mode = NOT_SET;
	client->is_loged = false;
	client->server = server;
	client->shouldContinue = true;
	return (0);
}
