#include <stdio.h>
#include "command_line_parser.h"
#include "server.h"

int					main(int ac, char **av)
{
	char			*path;
	unsigned short	port;
	
	if (ac != 3)
	{
		dprintf(2, "Usage : ./%s port path\n", av[1]);
		return (1);
	}
	if (command_line_parser(av, &path, &port))
	{
		dprintf(2, "Error while parsing command line arguments\n");
		return (1);
	}
	server(path, port);
	return (0);
}
