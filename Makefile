##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	src/

SRC		=	$(SRC_DIR)strlen.s	\
			$(SRC_DIR)strchr.s	\
			$(SRC_DIR)memset.s	\
			$(SRC_DIR)memcpy.s	\
			$(SRC_DIR)strcmp.s	\
			$(SRC_DIR)memmove.s	\
			$(SRC_DIR)strncmp.s	\
			$(SRC_DIR)strcasecmp.s
#			$(SRC_DIR)rindex.s	\
#			$(SRC_DIR)strpbrk.s	\
#			$(SRC_DIR)strstr.s	\
#			$(SRC_DIR)strpbrk.s	\
#			$(SRC_DIR)strcspn.s	\

OBJ		=	$(SRC:.s=.o)

LDFLAGS		=	-shared

NAME		=	libasm.so

all:		$(NAME)

$(NAME):	$(OBJ)
		$(LD) -o $(NAME) $(OBJ) $(LDFLAGS)

%.o:		%.s
		nasm -felf64 $< -o $@

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
