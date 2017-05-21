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
#include <stdio.h>
#include <netdb.h>
#include <memory.h>
#include <arpa/inet.h>
#include "server.h"
#include "tools.h"

static int	create_socket()
{
	struct protoent *pe;
	int fd;
	
	pe = getprotobyname("TCP");
	if (!pe)
	{
		dprintf_call(2, "Can't start TCP socket (error:getProtoByName)\n");
		return (-1);
	}
	fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (fd == -1)
	{
		dprintf_call(2, "Can't start TCP socket (error:socket)\n");
		return (-1);
	}
	return (fd);
}

static int	bind_socket(int fd, unsigned short port)
{
	struct sockaddr_in addr;
	
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_family = AF_INET;
	if ((setsockopt(fd, SOL_SOCKET, SO_REUSEADDR,
					(const char *) &addr, sizeof(addr))) == -1)
	{
		dprintf_call(2, "Can't start TCP socket (error:sockopt)\n");
		return (1);
	}
	if (bind(fd, (struct sockaddr *) &addr, sizeof(struct sockaddr_in)) == -1)
	{
		dprintf_call(2, "Can't start TCP socket (error:bind)\n");
		return (1);
	}
	return (0);
}

static int	listen_init(int fd)
{
	if (listen(fd, QUEUE_SIZE) == -1)
	{
		dprintf_call(2, "Can't start TCP socket (error:listen)\n");
		if (close(fd) == -1)
		{
			dprintf_call(2, "Close failed on socket\n");
			return (1);
		}
		return (1);
	}
	return (0);
}

static void	init_server_struct(t_server *server)
{
	char ac[256];
	struct hostent *phe;
	struct in_addr locaddr;
	
	server->shouldStop = false;
	gethostname(ac, sizeof(ac));
	phe = gethostbyname(ac);
	memcpy(&locaddr, phe->h_addr_list[0], sizeof(struct in_addr));
	strcpy(server->ip, inet_ntoa(locaddr));
	dprintf_call(2, "DEBUG: ServerLocalIp is :%s\n", server->ip);
}
int	server_init(t_server *server)
{
	init_server_struct(server);
	if ((server->fd = create_socket()) == -1)
		return (1);
	if (bind_socket(server->fd, server->port))
		return (1);
	if (listen_init(server->fd))
		return (1);
	return (0);
}
