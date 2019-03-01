##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SYSCALL_DIR	=	syscall/

SRC		=	get_next_line.c	\
			syscall_asm_generator.c	\

BONUS_SRC	=	$(wildcard $(SYSCALL_DIR)*.s)
BONUS_SRC	:=	$(filter-out $(SYSCALL_DIR)times.s, $(BONUS_SRC))

OBJ		=	$(SRC:.c=.o)
BONUS_OBJ	=	$(BONUS_SRC:.s=.o)

CFLAGS		=	-W -Wall -Wextra	\
			-O3

LDFLAGS		=	-shared

NAME		=	syscall_asm_generator
BONUS_NAME	=	libsyscall_asm.so

generator:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)
		./$(NAME)

asm:		$(BONUS_OBJ)
		$(LD) -o $(BONUS_NAME) $(BONUS_OBJ) $(LDFLAGS)

all:		generator asm

%.o:		%.s
		nasm -felf64 $< -o $@

clean:
		@$(RM) $(OBJ)
		@$(RM) $(BONUS_OBJ)

fclean:		clean
		@$(RM) $(NAME)
		@$(RM) $(BONUS_NAME)
		@$(RM) $(BONUS_SRC)
		@$(RM) $(SYSCALL_DIR)times.s

re:		fclean generator asm

.PHONY:		all clean fclean re generator asm
