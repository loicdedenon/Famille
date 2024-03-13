##
## EPITECH PROJECT, 2024
## B-PSU-200-NCY-1-minishell-damien.metzinger
## File description:
## Makefile
##

SRC =	$(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

NAME = exercice

CFLAGS = -Wall -Wextra -g -lcsfml-graphics -lcsfml-window -lcsfml-system -Wno-deprecated-declarations

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f src/*.o
	rm -f vgcore.*
	rm -f *~
	rm -f *.log
	rm -f *.a
	rm -f #*#
	rm -f valgrind-out.txt*

fclean:
	make clean
	rm -f $(NAME)

re: fclean all

error:
	make fclean
	make
	clear
	valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME)
	make fclean

code:
	make fclean
	coding-style . .
	clear
	cat coding-style-reports.log
	rm -f coding-style-reports.log

git: fclean
	@echo "what do you want to push ?:"; \
	read ADD;\
	echo "$$ADD"; \
	git add $$ADD;
	@echo "what did you change about your code ?"; \
	read ASW; \
	git commit -m "$$ASW"; \
	git push;
	clear;

warn:fclean
	clear
	make --debug
	make fclean

42:
	@echo "hello ! you've stumbled upon a secret !";

.PHONY = all $(NAME) clean fclean re
