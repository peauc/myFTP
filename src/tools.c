//
// Created by peau_c on 5/15/17.
//

#include <ctype.h>
#include <sys/stat.h>
#include "tools.h"

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
