##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	get_next_line.c	\
			syscall_asm_generator.c	\

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -Werror	\
			-O3

NAME		=	syscall_asm_generator

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		@rm $(OBJ)

fclean:		clean
		@rm $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
