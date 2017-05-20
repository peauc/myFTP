//
// Created by peau_c on 5/18/17.
//

#include "get_next_command.h"
#include "command_handler.h"
#include "command_functions.h"

static const t_comparator comparator[15] =
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
		};

int	server_handle_command(t_command *command, t_client *client)
{
	int	i;
	
	i = 0;
	while (i < 15)
	{
		if (comparator[i].instruction == command->instruction)
			comparator[i].function(command->arguments, client);
			i++;
	}
	return (0);
}


