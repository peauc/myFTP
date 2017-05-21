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
#include <stdlib.h>
#include <tools.h>
#include "client_init.h"
#include "command_handler.h"

int		command_list(__attribute__((unused))char *argument, t_client *client)
{
	int	target_fd;
	int	tmp_fd_holder;
	
	if (client->mode == NOT_SET)
	{
		send_mode_not_set_response(client);
		return (1);
	}
	if (client->mode == PASSIV)
	    target_fd = accept_connection_from_client(client);
	else
		target_fd = client->fd;
	write_on_socket(client->fd, "150 Opening binary mode connection\n");
	tmp_fd_holder = dup(1);
	dup2(target_fd, 1);
	system("ls");
	dup2(tmp_fd_holder, 1);
	write_on_socket(target_fd, "226 Transfert complete\r\n");
	if (target_fd != client->fd)
		close(target_fd);
	return (0);
}
