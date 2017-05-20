//
// Created by peau_c on 5/18/17.
//

#ifndef MYFTP_COMMAND_HANDLER_H
#define MYFTP_COMMAND_HANDLER_H

#include "get_next_command.h"
#include "server.h"

typedef struct	s_comparator
{
	t_instructions instruction;
	int (*function)(char *, t_client *);
}				t_comparator;

int server_handle_command(t_command *command, t_client *client);

#endif //MYFTP_COMMAND_HANDLER_H
