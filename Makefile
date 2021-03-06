##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	src/
BONUS_DIR	=	bonus/
TESTS_DIR	=	tests/

SRC		=	$(SRC_DIR)strlen.s	\
			$(SRC_DIR)strchr.s	\
			$(SRC_DIR)memset.s	\
			$(SRC_DIR)memcpy.s	\
			$(SRC_DIR)strcmp.s	\
			$(SRC_DIR)memmove.s	\
			$(SRC_DIR)strncmp.s	\
			$(SRC_DIR)strcasecmp.s	\
			$(SRC_DIR)rindex.s	\
			$(SRC_DIR)strstr.s	\
			$(SRC_DIR)strpbrk.s	\
			$(SRC_DIR)strcspn.s	\
			$(SRC_DIR)atoi.s	\
			$(SRC_DIR)putchar.s	\
			$(SRC_DIR)my_sort_int_array.s	\
#			$(SRC_DIR)puts.s

OBJ		=	$(SRC:.s=.o)

LDFLAGS		=	-shared

NAME		=	libasm.so

all:		$(NAME)

$(NAME):	$(OBJ)
		$(LD) -o $(NAME) $(OBJ) $(LDFLAGS)

bonus:
		@$(MAKE) re -C $(BONUS_DIR) --no-print-directory

%.o:		%.s
		nasm -felf64 $< -o $@

clean:
		@$(MAKE) clean -C $(BONUS_DIR) --no-print-directory
		@$(MAKE) clean -C $(TESTS_DIR) --no-print-directory
		@$(RM) $(OBJ)

fclean:		clean
		@$(MAKE) fclean -C $(BONUS_DIR) --no-print-directory
		@$(MAKE) fclean -C $(TESTS_DIR) --no-print-directory
		@$(RM) $(NAME)
		@$(RM) $(TESTS_DIR)$(NAME)

tests_run:	re
		mv $(NAME) $(TESTS_DIR)
		@$(MAKE) -C $(TESTS_DIR) --no-print-directory

re:		fclean all

.PHONY:		all bonus clean fclean tests_run re
