/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/

#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "tools.h"
#include "command_handler.h"

static bool	_check_exploit(char *argument, char *path)
{
	char *resolved_path;
	
	resolved_path = realpath(argument, NULL);
	if (resolved_path == NULL)
	{
		if (access(argument, W_OK) == -1)
		{
		    dprintf_call(2, "Access did not permit deletion on argument %s\n",
						 argument);
			return (true);
		}
		return (false);
	}
	if (strstr(resolved_path, path) == NULL)
	{
		free (resolved_path);
		return (true);
	}
	free (resolved_path);
	return (false);
}

int		command_dele(char *argument, t_client *client)
{
	if (strcmp(argument, "") == 0
		|| _check_exploit(argument, client->server->path))
	{
		send_wrong_dele_argument(client);
		return (1);
	}
	if (remove(argument) == -1)
	{
		send_wrong_dele_argument(client);
		return (1);
	}
	send_okay_dele_argument(client);
	return (0);
}
