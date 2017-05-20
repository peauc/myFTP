//
// Created by peau_c on 5/18/17.
//

#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "server.h"

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

