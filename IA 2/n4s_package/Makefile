##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## e
##

SRC	=	lib/action_management.c	\
		lib/algoia.c	\
		lib/main.c	\
		lib/send_info.c	\



OBJ	=	$(SRC:.c=.o)

NAME	=	ai

all: $(NAME)
$(NAME):	$(OBJ)
	gcc -o $(NAME)  $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	rm -f *.c~
	rm -f *.~

re: fclean all
