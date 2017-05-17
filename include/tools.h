//
// Created by peau_c on 5/15/17.
//

#ifndef MYFTP_TOOLS_H
#define MYFTP_TOOLS_H

#include <stdbool.h>

int		write_on_socket(int fd, const char * const message);
bool	directory_exists(char *path);
bool	is_number(char *number);
int		dprintf_call(int fd, char *str, ...);


#endif //MYFTP_TOOLS_H
