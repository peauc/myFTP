/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/


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
