//
// Created by peau_c on 5/12/17.
//

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tools.h"
#include "command_line_parser.h"

int command_line_parser(int ac, char **av, char **path, unsigned short *port)
{
	if (ac != 3)
	{
		dprintf_call(2, "Usage: %s port path\n", av[0]);
		return (1);
	}
	if (!is_number(av[1]))
	{
		dprintf_call(2, "%s is not a number\n", av[1]);
		return (1);
	}
	if (!directory_exists(av[2])) {
		dprintf_call(2, "Cannot access directory %s\n", av[2]);
		return (1);
	}
	if (atoi(av[1]) > USHRT_MAX) {
		dprintf_call(2, "Port is too large, max value is %d\n", USHRT_MAX);
		return (1);
	}
	*port = (unsigned short)atoi(av[1]);
	*path = strdup(av[2]);
	return (0);
}
