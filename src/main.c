#include <stdio.h>
#include "command_line_parser.h"
#include "server.h"

int					main(int ac, char **av)
{
	char			*path;
	unsigned short	port;
	
	if (command_line_parser(ac, av, &path, &port))
	{
		dprintf(2, "Error while parsing command line arguments\n");
		return (1);
	}
	server(path, port);
	return (0);
}
