/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/

#ifndef MYFTP_CLIENT_INIT_H
#define MYFTP_CLIENT_INIT_H

#include "server.h"

int		create_new_data_socket(t_client *client);
int		client_init(t_client *client, t_server *server);
int		accept_connection_from_client(t_client *client);

#endif //MYFTP_CLIENT_INIT_H
