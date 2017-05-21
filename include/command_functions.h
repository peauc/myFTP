/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/

#ifndef MYFTP_COMMAND_FUNCTIONS_H
#define MYFTP_COMMAND_FUNCTIONS_H

#include "server.h"

int		command_user(char *argument, t_client *client);
int		command_pass(char *argument, t_client *client);
int		command_cwd(char *argument, t_client *client);
int		command_cdup(char *argument, t_client *client);
int		command_dele(char *argument, t_client *client);
int		command_help(char *argument, t_client *client);
int		command_list(char *argument, t_client *client);
int		command_noop(char *argument, t_client *client);
int		command_pass(char *argument, t_client *client);
int		command_pasv(char *argument, t_client *client);
int		command_port(char *argument, t_client *client);
int		command_pwd(char *argument, t_client *client);
int		command_quit(char *argument, t_client *client);
int		command_retr(char *argument, t_client *client);
int		command_stor(char *argument, t_client *client);
int		command_user(char *argument, t_client *client);
int		command_syst(char *argument, t_client *client);
int		command_unknown(char *argument, t_client *client);



#endif //MYFTP_COMMAND_FUNCTIONS_H
