##
## EPITECH PROJECT, 2021
## Desktop
## File description:
## Makefile
##

ECHO	=	/bin/echo -e

DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"

CC= g++ -std=c++17

CFLAGS= -Wall -g3

NAME= arcade

SRC = $(wildcard *.cpp) \
	$(wildcard link_library/*.cpp)	\

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) -ldl && $(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : arcade" $(DEFAULT)
	@cp arcade ../
	@rm -rf $(NAME)

clean:
	@rm -rf *.o

fclean: clean

re: fclean all
	