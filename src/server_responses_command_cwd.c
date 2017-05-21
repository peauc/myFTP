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
#include <string.h>
#include "server.h"
#include "tools.h"

int			send_cwd_folder_not_exist(t_client *client)
{
	return (write_on_socket(client->fd, "550 Folder dosn't exist\n"));
}

int			send_wrong_cwd_response(t_client *client)
{
	return (write_on_socket(client->fd, "550 Access denied\r\n"));
}

int			send_good_cwd_response(t_client *client, char *path)
{
	char	*message;
	int		ret;
	
	message = malloc((strlen(path) + 30) * sizeof(char));
	strcpy(message, "200 Directory changed to : ");
	strcat(message, path);
	strcat(message, "\r\n");
	dprintf_call(2, "good cwd response |%s|\n", message);
	ret = write_on_socket(client->fd, message);
	free(message);
	return (ret);
}

