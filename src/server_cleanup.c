/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/

#include <stdio.h>
#include <unistd.h>
#include "server.h"
#include "tools.h"

int server_cleanup(t_server *server)
{
	if (close(server->fd) == -1)
	{
		dprintf_call(2, "Can't close the socket inside the cleanup\n");
		return (1);
	}
	return (0);
}
