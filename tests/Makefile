##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	src/

SRC		=				\
		$(SRC_DIR)tests-my_strlen.c	\
		$(SRC_DIR)tests-my_strchr.c	\
		$(SRC_DIR)tests-my_memset.c	\
		$(SRC_DIR)tests-my_memcpy.c	\
		$(SRC_DIR)tests-my_strcmp.c	\
		$(SRC_DIR)tests-my_rindex.c	\
		$(SRC_DIR)tests-my_strstr.c	\
		$(SRC_DIR)tests-my_strcspn.c	\
		$(SRC_DIR)tests-my_strpbrk.c	\
		$(SRC_DIR)tests-my_strncmp.c	\
		$(SRC_DIR)tests-my_strcasecmp.c	\
		$(SRC_DIR)tests-my_atoi.c	\
		$(SRC_DIR)tests-my_putchar.c	\
		$(SRC_DIR)tests-my_sort_int_array.c	\
#		$(SRC_DIR)tests-my_puts.c

OBJ		=	$(SRC:.c=.o)

LDFLAGS		=	-lcriterion --coverage -ldl

CFLAGS		+=	-W -Wall -Wextra

NAME		=	test

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		./$(NAME)

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
