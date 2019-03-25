##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

all:
	make -C snake
	make -C pacman
	# make -C game_2

pacman:
	make -C pacman

g2:
	make -C game_2

snake:
	make -C snake

clean:
	make clean -C snake
	make clean -C pacman
	# make clean -C game_2
		@echo "Clean faite!"

fclean: clean
	make clean fclean -C snake
	make clean fclean -C pacman
	# make clean fclean -C game_2
		@echo "FClean faite!"

re:	fclean all
		@echo "Re fait!"

tests_run:
	make -C game_1/tests/
	make -C game_2/tests/
	make -C snake/tests/

.PHONY: clean fclean re all tests_run
