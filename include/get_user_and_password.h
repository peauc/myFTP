/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/


#ifndef MYFTP_GET_USER_AND_PASSWORD_H
#define MYFTP_GET_USER_AND_PASSWORD_H

#include <server.h>

#define MAXIMUM_TRY_PER_SESSION 10

int get_user_and_pass(t_client *client);

#endif //MYFTP_GET_USER_AND_PASSWORD_H
