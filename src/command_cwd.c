/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/

#include <string.h>
#include <unistd.h>
#include "tools.h"
#include "command_handler.h"

int			command_cwd(char *argument, t_client *client)
{
	char	*server_path;
	char	*actual_path;
	char 	*new_cwd;
	
	server_path = client->server->path;
	actual_path = getcwd(NULL, 0);
	if (chdir(argument) == -1)
	{
		send_cwd_folder_not_exist(client);
		return (1);
	}
	new_cwd = getcwd(NULL, 0);
	dprintf_call(2, "%s %s\n", new_cwd, server_path);
	if (strstr(new_cwd, server_path) == NULL)
	{
		chdir(actual_path);
		send_wrong_cwd_response(client);
		return (0);
	}
	send_good_cwd_response(client, new_cwd);
	return (0);
}
