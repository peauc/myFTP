/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/


#include <server.h>
#include <stdio.h>

int		send_good_pasv_command_response(t_client *client, char *ip)
{
	return (dprintf(client->fd, "227 Entering Passive Mode (%s,%d,%d)\r\n", ip, client->data_port / 256, client->data_port % 256));
}
