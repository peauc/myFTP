/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/


#ifndef MYFTP_GET_NEXT_COMMAND_H
#define MYFTP_GET_NEXT_COMMAND_H

#define FATAL_ERROR NULL
#define SYNTAX_ERROR (t_command *)-1

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
	SYST,
	NB_OF_INSTRUCTIONS
}						t_instructions;

typedef struct			s_command
{
	char				*arguments;
	t_instructions		instruction;
}						t_command;

// ##############################################################################
// # GET_NEXT_COMMAND.c															#
// ##############################################################################
t_command	*get_next_command(int fd);

#endif //MYFTP_GET_NEXT_COMMAND_H
