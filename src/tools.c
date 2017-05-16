//
// Created by peau_c on 5/15/17.
//

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/stat.h>
#include "tools.h"

int write_on_socket(int fd, const char * const message)
{
	if (write(fd, message, strlen(message)) == -1) {
		dprintf(2, "Cannot write on socket, aborting\n");
		return (1);
	}
	return (0);
}

bool	directory_exists(char *path)
{
	struct stat s_buf;
	
	stat(path, &s_buf);
	return (S_ISDIR(s_buf.st_mode));
}

bool	is_number(char *number)
{
	int i;
	
	i = 0;
	while (number[i])
	{
		if (!isdigit(number[i]))
		{
			return (false);
		}
	i++;
	}
	
	return (true);
}
