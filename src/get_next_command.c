//
// Created by peau_c on 5/12/17.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "server.h"
#include "get_next_command.h"

/*
static t_command	_convert_string_to_command(char *str)
{
	t_command		command;
	
	return (command);
}

static bool dont_contain_a_line(char *buffer, char **holder)
{
	int i;
	
	if (*buffer == NULL)
		return (false);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\r' && buffer[i + 1] == '\n' && buffer[i + 2])
		{
			if (*holder != NULL)
				free(*holder);
			*holder = strdup(buffer + i + 2);
			buffer[i + 2] = 0;
		}
		++i;
	}
	return (false);
}
static char			*_reader(int fd)
{
	static char		*holder = NULL;
	char			*buffer;
	
	buffer = NULL;
	while (dont_contain_a_line(buffer, &holder))
	{
		buffer = realloc(buffer, (buffer == NULL ? 0 : strlen(buffer)) + BUFFER_SIZE);
		if (read(fd, buffer, BUFFER_SIZE) == -1)
		{
			dprintf(2, "Error while reading in %s l'%d situated in %s\n",
					__FUNCTION__, __LINE__, __FILE__);
			return (NULL);
		}
	}
	return (buffer);
}
*/

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
		return (NULL);
	tmp[0] = 0;
	c[1] = 0;
	while ((error = read(fd, c, 1)) != 0)
	{
		if (error == -1 || (tmp = realloc(tmp, len)) == NULL)
			return (NULL);
		if (newline && c[0] == '\n')
			return (tmp[strlen(tmp)] = 0, tmp);
		newline = (c[0] == '\r' ? true : false);
		strcat(tmp, c);
		len++;
	}
	return ((error == 0 && tmp[0] == 0 ? NULL : tmp));
}

t_command			*get_next_command(int fd)
{
	t_command	*ret = NULL;
	char		*tmp;
	
	if ((tmp = _reader(fd)) == NULL)
	{
		//TODO:Error message
		return (NULL);
	}
	dprintf(2, "%s\n", tmp);
	//PLACE HOLDER SINCE IM TIRED AND NEED TO SLEEP, AND I TEST BEFORE PUSHING
	return (tmp);
}
