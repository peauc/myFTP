//
// Created by peau_c on 5/18/17.
//

#ifndef MYFTP_COMMAND_FUNCTIONS_H
#define MYFTP_COMMAND_FUNCTIONS_H

int		command_user(char *argmument, t_client *client);
int		command_pass(char *argmument, t_client *client);
int		command_cwd(char *argmument, t_client *client);
int		command_cdup(char *argmument, t_client *client);
int		command_dele(char *argmument, t_client *client);
int		command_help(char *argmument, t_client *client);
int		command_list(char *argmument, t_client *client);
int		command_noop(char *argmument, t_client *client);
int		command_pass(char *argmument, t_client *client);
int		command_pasv(char *argmument, t_client *client);
int		command_port(char *argmument, t_client *client);
int		command_pwd(char *argmument, t_client *client);
int		command_quit(char *argmument, t_client *client);
int		command_retr(char *argmument, t_client *client);
int		command_stor(char *argmument, t_client *client);
int		command_user(char *argmument, t_client *client);

#endif //MYFTP_COMMAND_FUNCTIONS_H
