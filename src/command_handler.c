/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/

#include "get_next_command.h"
#include "command_handler.h"
#include "command_functions.h"

static const t_comparator g_comparator[16] =
		{
				{USER, command_user},
				{PASS, command_pass},
				{CWD,  command_cwd},
				{CDUP, command_cdup},
				{QUIT, command_quit},
				{DELE, command_dele},
				{PWD,  command_pwd},
				{PASV, command_pasv},
				{PORT, command_port},
				{HELP, command_help},
				{NOOP, command_noop},
				{RETR, command_retr},
				{STOR, command_stor},
				{LIST, command_list},
				{SYST, command_syst}
		};

int	server_handle_command(t_command *command, t_client *client)
{
	int	i;
	
	i = 0;
	while (i < NB_OF_INSTRUCTIONS)
	{
		if (g_comparator[i].instruction == command->instruction)
		{
			g_comparator[i].function(command->arguments, client);
			return (0);
		}
			i++;
	}
	command_unknown(command->arguments, client);
	return (0);
}


