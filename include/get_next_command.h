//
// Created by peau_c on 5/12/17.
//

#ifndef MYFTP_GET_NEXT_COMMAND_H
#define MYFTP_GET_NEXT_COMMAND_H

typedef enum			s_instructions
{
	NONE = -1,
	USER,
	PASS,
	CWD,
	CDUP,
	QUIT,
	DELE,
	PWD,
	PASV,
	PORT,
	HELP,
	NOOP,
	RETR,
	STOR,
	LIST,
	NB_OF_INSTRUCTIONS
}						t_instructions;

typedef struct			s_command
{
	t_instructions		instruction;
	char				*arguments;
}						t_command;

// ##############################################################################
// # GET_NEXT_COMMAND.c															#
// ##############################################################################
t_command get_next_command();

#endif //MYFTP_GET_NEXT_COMMAND_H
