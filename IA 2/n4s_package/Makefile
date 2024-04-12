##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	=	./includes/printf/my_decimal.c \
		./includes/printf/my_expomaj.c \
		./includes/printf/my_expomin.c \
		./includes/printf/my_float.c \
		./includes/printf/my_float2.c \
		./includes/printf/my_hexamaj.c \
		./includes/printf/my_hexamin.c \
		./includes/printf/my_octet.c \
		./lib/my_isalpha.c \
		./lib/my_putchar.c \
		./lib/my_put_nbr.c \
		./lib/my_putstr.c \
		./lib/my_strcpy.c \
		./lib/my_strcmp.c \
		./lib/my_strncmp.c \
		./lib/my_strlen.c \
		./lib/my_strcat.c \
		./lib/my_strdup.c \
		./lib/split.c \
		./src/main.c \
		./src/cmds.c \
		./src/elements.c \
		./src/forward.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra

NAME	=	ai

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME)	$(SRC)	$(CFLAGS)

debug:	$(OBJ)
	gcc -o $(NAME) $(SRC) $(CFLAGS) -g

clean:
	rm -f $(OBJ)

clean+:	clean
	rm -f *~
	rm -f *#
	rm -f vgcore.*
	rm -f ./src/*~
	rm -f ./src/*#
	rm -f ./src/vgcore.*
	rm -f ./lib/*~
	rm -f ./lib/*#
	rm -f ./includes/*~
	rm -f ./includes/*#

fclean: clean+
	rm -f $(NAME)

re: fclean all

git: fclean
	git pull
	clear
	@echo "what files do you want to add ?:"; \
	read ADD;\
	echo "$$ADD as been added!"; \
	git add $$ADD;
	@echo "What do you want to push as commentary ?:"; \
	read ASW; \
	git commit -m "$$ASW"; \
	git push;
	clear;
