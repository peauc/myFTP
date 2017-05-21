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
#include <string.h>
#include <stdio.h>
#include "server.h"
#include "tools.h"

int	send_ok_response(t_client *client)
{
	return (write_on_socket(client->fd, "200 OK.\r\n"));
}


int	send_accepted_response(t_client *client)
{
	return (write_on_socket(client->fd,
							"220 Welcome to peauc's awesome server\r\n"));
}
