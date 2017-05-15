SRC_FILE=	main.c\
			command_line_parser.c\
			get_next_command.c\
			server.c\
			server_init.c\
			server_logic.c\
			server_cleanup.c\
			server_responses.c\
			tools.c\

SRC=		$(addprefix src/, $(SRC_FILE))

OBJ=		$(SRC:.c=.o)

INC=		-I./include/

NAME=		myftp

CFLAGS=		-W -Wall -Wextra

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