//
// Created by peau_c on 5/15/17.
//

#include "tools.h"

bool	directory_exists(char *path)
{
	struct stat s_buf;
	
	stat(path, &s_buf);
	return (IS_DIR(s_buf.st_mode));
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
	}
	
	return (true);
}
