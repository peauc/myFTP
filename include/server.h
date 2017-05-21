/*
** main.c for  in /home/peau_c/School/tek2/PSU_2016_myftp/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun May 21 18:53:13 2017
** Last update Sun May 21 18:53:16 2017
*/

#ifndef MYFTP_SERVER_H
#define MYFTP_SERVER_H

#define QUEUE_SIZE		42

#include <netinet/in.h>
#include <stdbool.h>

typedef enum			s_transfert_mode
{
	NOT_SET,
	PASSIV,
	ACTIVE
}						t_transfert_mode;

typedef struct			s_server
{
	int					fd;
	unsigned short		port;
	char				*path;
	bool				shouldStop;
	char 				ip[32];
}						t_server;

typedef struct			s_client
{
	int					fd;
	unsigned short		data_port;
	int 				data_fd;
	char 				*ip;
	struct sockaddr_in	s_in_client;
	bool				shouldContinue;
	bool				is_loged;
	t_server			*server;
	t_transfert_mode	mode;
}						t_client;

// ##############################################################################
// # SERVER.c																	#
// ##############################################################################
int		server(char *, unsigned short);

// ##############################################################################
// # SERVER_INIT.c																#
// ##############################################################################
int		server_init(t_server *server);

// ##############################################################################
// # SERVER_CLEANUP.c															#
// ##############################################################################
int		server_cleanup(t_server *server);

// ##############################################################################
// # SERVER_RESPONSES.c															#
// ##############################################################################
int		send_accepted_response(t_client *client);
int		send_ok_response(t_client *client);

// ##############################################################################
// # SERVER_RESPONSES_COMMANDS.c												#
// ##############################################################################
int		send_quit_response(t_client *client);
int		send_good_pwd_response(t_client *client, char *path);
int		send_mode_not_set_response(t_client *client);

// ##############################################################################
// # SERVER_RESPONSES_COMMANDS_PASV.c											#
// ##############################################################################
int		send_good_pasv_command_response(t_client *client, char *ip);

// ##############################################################################
// # SERVER_RESPONSES_COMMANDS_DELE.c											#
// ##############################################################################
int		send_wrong_dele_argument(t_client *client);
int		send_okay_dele_argument(t_client *client);

// ##############################################################################
// # SERVER_RESPONSES_COMMANDS_RETR.c											#
// ##############################################################################
int	send_file_missing_retr(t_client *client);


// ##############################################################################
// # SERVER_RESPONSES_LOGIN.c													#
// ##############################################################################
int		send_cwd_folder_not_exist(t_client *client);
int		send_wrong_cwd_response(t_client *client);
int		send_good_cwd_response(t_client *client, char *path);

// ##############################################################################
// # SERVER_RESPONSES_LOGIN.c													#
// ##############################################################################
int		send_wrong_user_pass_response(t_client *client);
int		send_wrong_login_response(t_client *client);
int		send_input_pass_response(t_client *client);
int		send_wrong_login_order(t_client *client);
int		send_good_login_response(t_client *client);

// ##############################################################################
// # SERVER_LOGIC.c																#
// ##############################################################################
int		server_logic_loop(t_client *client);


#endif //MYFTP_SERVER_H
