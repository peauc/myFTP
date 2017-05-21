/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "server.h"
#include "get_next_command.h"
#include "tools.h"

static const char *instruction_index[] =
{
		"USER",
		"PASS",
		"CWD",
		"CDUT",
		"QUIT",
		"DELE",
		"PWD",
		"PASV",
		"PORT",
		"HELP",
		"NOOP",
		"RETR",
		"STOR",
		"LIST",
		"SYST",
};

static t_instructions	_convert_to_instruction(char *str)
{
	int	i;
	
	i = 0;
	while (instruction_index[i])
	{
		dprintf_call(2, "loop |%s| |%s|\n", str, instruction_index[i]);
		if (strcmp(str, instruction_index[i]) == 0)
			return ((t_instructions)i);
		i++;
	}
	return (NONE);
}

//May be fucked, have to test thoroughly
static bool	_is_valid_syntax(char *str)
{
	size_t	i;
	size_t	count;
	
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	if (count > 1)
	{
		dprintf_call(2, "There is more than one space in the answer from the client\n");
		return (false);
	}
	i = strlen(str) - 1;
	if (i == 0 || (str[i] != '\n' && str[i - 1] == '\r'))
	{
		dprintf_call(2, "Answer from the client does not end with CRLF\n");
		return (false);
	}
	return (true);
}


static t_command	*_convert_string_to_command(char *str)
{
	t_command		*command;
	char			*string;
	
	if (!_is_valid_syntax(str))
	{
	    dprintf_call(2, "%s-%d: Illegal instruction\n", __FUNCTION__, __LINE__);
		return (SYNTAX_ERROR);
	}
	if ((command = malloc(sizeof(t_command))) == NULL)
			return (FATAL_ERROR);
	string = index(str, ' ') + 1;
	dprintf_call(2, "%p\n", string);
	if (string == (char *)1 || string[0] == 0)
	{
	    if (string != (char *)1)
			*(string - 1) = 0;
		command->arguments = "";
	}
	else
	{
		command->arguments = strdup(string);
		*index(str, ' ') = 0;
	}
	command->instruction = _convert_to_instruction(str);
	dprintf_call(2, "Converted a command %s to %d %s\n", str, command->instruction, command->arguments);
	return (command);
}

static char *_reader(int fd)
{
	char	c[2];
	char	*tmp;
	ssize_t	error;
	size_t	len;
	bool	newline;
	
	newline = false;
	len = 2;
	if (!(tmp = malloc(1)))
		return (FATAL_ERROR);
	tmp[0] = 0;
	c[1] = 0;
	while ((error = read(fd, c, 1)) != 0)
	{
		if (error == -1 || (tmp = realloc(tmp, len)) == NULL)
			return (FATAL_ERROR);
		if (newline && c[0] == '\n')
			return (tmp[strlen(tmp)] = 0, tmp);
		newline = (c[0] == '\r' ? true : false);
		strcat(tmp, c);
		len++;
	}
	return ((error == 0 && tmp[0] == 0 ? FATAL_ERROR : tmp));
}

t_command			*get_next_command(int fd)
{
	t_command	*ret = NULL;
	char		*tmp;
	
	if ((tmp = _reader(fd)) == NULL)
	{
		//TODO:Error message
		return (FATAL_ERROR);
	}
	if (strlen(tmp) > 0 && tmp[strlen(tmp) - 1] == '\r')
		tmp[strlen(tmp) - 1] = 0;
	dprintf_call(2, "Data received = |%s|\n", tmp);
	if ((ret = _convert_string_to_command(tmp)) == SYNTAX_ERROR || ret == FATAL_ERROR)
	{
		dprintf_call(2, "Could not convert string to a valid server command\n");
		return (ret);
	}
	free(tmp);
	return (ret);
}
