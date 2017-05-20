SRC_FILE=	main.c\
		command_line_parser.c\
		get_next_command.c\
		server.c\
		server_init.c\
		server_logic.c\
		server_cleanup.c\
		server_responses.c\
		server_responses_commands.c\
		server_responses_login.c\
		tools.c\
		get_user_and_password.c\
		command_cdup.c\
		command_cwd.c\
		command_dele.c\
		command_handler.c\
		command_help.c\
		command_list.c\
		command_noop.c\
		command_pass.c\
		command_pasv.c\
		command_port.c\
		command_pwd.c\
		command_quit.c\
		command_retr.c\
		command_stor.c\
		command_user.c\

SRC=		$(addprefix src/, $(SRC_FILE))

DEBUG=		no

OBJ=		$(SRC:.c=.o)

INC=		-I./include/

NAME=		myftp

ifeq ($(DEBUG), no)
CFLAGS=		-W -Wall -Wextra
else
CFLAGS=		-W -Wall -Wextra -g -O0 -ggdb -DDEBUG
endif

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

bootstrap:
		gcc -c bootstrap bootstrap/*.c

clean:
		@echo -e "\t/!\\ Clean  /!\\"
		@rm -rf $(OBJ)

fclean:		clean
		@echo -e "\t/!\\ FClean /!\\"
		@rm -rf $(NAME)

re:		fclean all

.c.o:
		$(CC) $(INC) $(CFLAGS) -c $< -o $@
