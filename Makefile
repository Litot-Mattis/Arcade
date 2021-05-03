##
## EPITECH PROJECT, 2021
## Desktop
## File description:
## Makefile
##

NAME = arcade

GA= ./lib/games/
CO= ./core/
GR= ./lib/

all: $(NAME)

games:
	@$(MAKE) -C $(GA)

core:
	@$(MAKE) -C $(CO)

graphicals:
	@$(MAKE) -C $(GR)

$(NAME):
	@$(MAKE) -C $(GA)
	@$(MAKE) -C $(CO)
	@$(MAKE) -C $(GR)

clean:
	@rm -rf $(NAME)

fclean: clean
	@make fclean -C $(GA)
	@make fclean -C $(CO)
	@make fclean -C $(GR)
	@rm -rf arcade

re: fclean all $(FOLDERS)

.PHONY: all clean fclean re core graphicals games
