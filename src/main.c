#include <stdio.h>
#include "command_line_parser.h"
#include "server.h"
#include "tools.h"

int					main(int ac, char **av)
{
	char			*path;
	unsigned short	port;
	
	if (command_line_parser(ac, av, &path, &port))
	{
		dprintf_call(2, "Error while parsing command line arguments\n");
		return (1);
	}
	if (server(path, port))
		return (1);
	return (0);
}
