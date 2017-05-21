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
#include <unistd.h>
#include "command_handler.h"

int			command_pwd(__attribute__((unused))char *argument, t_client *client)
{
	char	*path;
	int		ret;
	
	path = getcwd(NULL, 0);
	if (path == NULL)
		return (1);
	ret = send_good_pwd_response(client, path);
	free(path);
	return (ret);
}
