##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## file
##

CC = gcc
CFLAGS = -g -Wall -Wextra
LIBS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm

SRC	=	lib/my_printf.c				\
		lib/my_binary.c				\
		lib/my_putchar.c			\
		lib/my_octal.c				\
		lib/my_atoi.c				\
		lib/my_isalnum.c			\
		lib/my_unsigned_decimal.c	\
		lib/hexadecimaldown.c		\
		lib/hexadecimalup.c			\
		lib/my_put_nbr.c			\
		lib/my_putstr.c				\
		lib/my_strcat.c				\
		lib/my_strcpy.c				\
		lib/my_strdup.c				\
		lib/my_strlen.c				\
		lib/my_strncpy.c			\
		lib/my_str_to_word_array.c	\
		lib/my_swap.c				\
		lib/my_strcmp.c				\
		lib/my_strncmp.c			\
		lib/my_isalpha.c			\
		lib/my_strclean.c			\
		lib/my_str_isalpha.c		\
		lib/parser.c				\
		src/my_radar.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *.o

re:	fclean all

git: fclean
	@echo "what do you want to push ?:"; \
	read ADD;\
	echo "$$ADD"; \
	git add $$ADD;
	@echo "what did you change about your code ?"; \
	read ASW; \
	git commit -m "$$ASW"; \
	git push;

code:
	make fclean
	coding-style . .
	clear
	cat coding-style-reports.log

error:
	make fclean
	make
	valgrind -s --leak-check=full --show-leak-kinds=all ./$(NAME)
