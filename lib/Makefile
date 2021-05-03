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

NAME= graphicals

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -shared -fPIC $(wildcard ncurse/*.cpp) -lncurses -o arcade_ncurses.so && $(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : Ncurse Lib" $(DEFAULT)
	@$(CC) $(CFLAGS) -shared -fPIC $(wildcard sfml/*.cpp) -lsfml-graphics -lsfml-window -lsfml-system -o arcade_sfml.so && $(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : Sfml Lib" $(DEFAULT)
	@$(CC) $(CFLAGS) -shared -fPIC $(wildcard sdl2/*.cpp) -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -o arcade_sdl2.so && $(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : Sdl Lib" $(DEFAULT)

clean:
	@rm -rf ncurse/*.o
	@rm -rf nibbler/*.o

fclean: clean
	@rm -rf arcade_*.so

re: fclean all