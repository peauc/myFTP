/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "client_init.h"
#include "tools.h"
#include "command_handler.h"

int		command_retr(char *argument, t_client *client)
{
	char	buffer[4096];
	int		fd;
	int		connect_fd;
	ssize_t	ret;
	
	if (strcmp(argument, "") == 0)
	{
		send_file_missing_retr(client);
		return (1);
	}
	if (client->mode == NOT_SET)
	{
		send_mode_not_set_response(client);
		return (1);
	}
	if ((fd = open(argument, O_RDONLY)) == -1)
	{
		dprintf_call(2, "Could not open file %s\n", argument);
		return (1);
	}
	connect_fd = accept_connection_from_client(client);
	write_on_socket(client->fd, "150 Opening binary mode\n");
	while ((ret = read(fd, buffer, 4095)) > 0)
	{
		if (write_on_socket(connect_fd, buffer) == -1)
		{
			dprintf_call(2, "Data write failed\r\n");
			return (1);
		}
	}
	close(connect_fd);
	
	return (0);
}
