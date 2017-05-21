/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
** 
** Made by 
** Login   <peau_c@epitech.net>
** 
** Started on  Sun May 21 18:53:13 2017 
** Last update Sun May 21 18:53:16 2017 
*/

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
