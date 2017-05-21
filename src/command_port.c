/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/

#include <tools.h>
#include "command_handler.h"

int		command_port(__attribute__((unused)) char *argument, t_client *client)
{
	write_on_socket(client->fd, "550 Access denied\r\n");
	return (0);
}
