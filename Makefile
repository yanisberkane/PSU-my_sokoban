##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Program and library compilation
##

SRC	=	src/main.c \
		src/map_parsing/map_parsing.c \
		src/map_parsing/map_coherence.c \
		src/map_parsing/cols_checker.c \
		src/run_game.c \
		src/manage_input.c \
		src/manage_filling.c \
		src/manage_game_status.c \

CFLAGS	=	-Wall -Wextra -I./include

LDFLAGS	=	-L./lib/my -lmy -std=c99 -lncurses -g3

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	make	-C	lib/my/
	make	-C	lib/my_matrix/
	$(CC)	-o	$(NAME)	$(CFLAGS) $(SRC) -g $(LDFLAGS)

clean:
	rm -f	$(OBJ)
	rm -f *~
	rm -f '#'*'#'
	make	-C	lib/my/	clean
	make	-C	lib/my_matrix/ clean

fclean:	clean
	rm	-f	$(NAME)
	make	-C	lib/my/	fclean
	make	-C	lib/my_matrix/ fclean

re:	fclean all

.PHONY = $(NAME) clean fclean re
