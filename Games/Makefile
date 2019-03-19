##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

all:
	make -C game_1
	make -C game_2
	make -C snake

pacman:
	make -C pacman

g2:
	make -C game_2

snake:
	make -C snake

clean:
	make clean -C game_1
	make clean -C game_2
	make clean -C snake
		@echo "Clean faite!"

fclean: clean
	make fclean -C game_1
	make fclean -C game_2
	make fclean -C snake
		@echo "FClean faite!"

re:	fclean all
		@echo "Re fait!"

tests_run:
	make -C game_1/tests/
	make -C game_2/tests/
	make -C snake/tests/

.PHONY: clean fclean re all tests_run
