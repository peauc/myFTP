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

int		command_retr(__attribute__((unused)) char *argument, t_client *client)
{
	write_on_socket(client->fd, "550 Access denied\r\n");
	return (0);
}
