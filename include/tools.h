/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/


#ifndef MYFTP_TOOLS_H
#define MYFTP_TOOLS_H

#include <stdbool.h>

int		write_on_socket(int fd, const char * const message);
bool	directory_exists(char *path);
bool	is_number(char *number);
int		dprintf_call(int fd, char *str, ...);


#endif //MYFTP_TOOLS_H
