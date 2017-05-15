//
//Created by peau_c on 5/12/17.
//

#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include "server.h"

static int				create_socket()
{
	struct protoent		*pe;
	int					fd;
	
	pe = getprotobyname("TCP");
	if (!pe) {
		dprintf(2, "Can't start TCP socket (error:getProtoByName)\n");
		return (-1);
	}
	fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (fd == -1) {
		dprintf(2, "Can't start TCP socket (error:socket)\n");
		return (-1);
	}
	return (0);
}

static int				bind_socket(int fd, unsigned short port) {
	struct sockaddr_in	addr;
	
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_family = AF_INET;
	if (bind(fd, (struct sockaddr *) &addr, sizeof(struct sockaddr_in)) == -1) {
		dprintf(2, "Can't start TCP socket (error:bind)\n");
		return (1);
	}
	return (0);
}

static int				listen_init(int fd) {
	if (listen(fd, QUEUE_SIZE) == -1) {
		dprintf(2, "Can't start TCP socket (error:listen)\n");
		if (close(fd) == -1) {
			dprintf(2, "Close failed on socket\n");
			return (1);
		}
		return (1);
	}
	return (0);
}

int server_init(t_server *server)
{
	server->shouldStop = false;
	if ((server->fd = create_socket()) == -1)
		return (1);
	//TODO: vrai port
	if (bind_socket(server->fd, server->port))
		return (1);
	if (listen_init(server->fd))
		return (1);
	return (0);
}
