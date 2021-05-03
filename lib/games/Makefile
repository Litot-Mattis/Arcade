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

NAME= games

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -shared -fPIC $(wildcard pacman/*.cpp) -o arcade_pacman.so && $(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : PacMan" $(DEFAULT)
	@$(CC) $(CFLAGS) -shared -fPIC $(wildcard nibbler/*.cpp) -o arcade_nibbler.so && $(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : Nibbler" $(DEFAULT)
	@cp arcade_*.so ../
	@rm -rf lib*.so

clean:
	@rm -rf pacman/*.o
	@rm -rf nibbler/*.o

fclean: clean
	@rm -rf arcade_*.so

re: fclean all