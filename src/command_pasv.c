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
#include "client_init.h"
#include "command_handler.h"

int		command_pasv(__attribute__((unused)) char *argument, t_client *client)
{
	dprintf_call(2, "Entering command passv\n");
	char	*ip;
	int		i;
	
	i = 0;
	if (create_new_data_socket(client))
		return (1);
	client->mode = PASSIV;
	if ((ip = strdup(client->ip)) == NULL)
		return (1);
	while (ip[i])
	{
		if (ip[i] == '.')
			ip[i] = ',';
		i++;
	}
	i = send_good_pasv_command_response(client, ip);
	free(ip);
	return (i);
}
