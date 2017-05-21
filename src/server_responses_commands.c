/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/

#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "server.h"

int			send_mode_not_set_response(t_client *client)
{
	static const char * const message = "520 Please set the data transfert "
			"mode with either PORT or PASV.\r\n";
	return (write_on_socket(client->fd, message));
}

int			send_good_pwd_response(t_client *client, char *path)
{
	int		ret;
	char	*message;
	
	if ((message = malloc(sizeof(char) * (strlen(path) + 30))) == NULL)
		return (1);
	strcpy(message, "257 Current directory is : ");
	strcat(message, path);
	strcat(message, "\r\n");
	ret = write_on_socket(client->fd, message);
	return (ret);
}

int			send_quit_response(t_client *client)
{
	return (write_on_socket(client->fd, "221 Goodbye.\r\n"));
}

