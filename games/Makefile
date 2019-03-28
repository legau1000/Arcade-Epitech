##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

all:
	make -C snake
	make -C pacman
	# make -C nibbler

pacman:
	make -C pacman

nibbler:
	make -C nibbler

snake:
	make -C snake

clean:
	make clean -C snake
	make clean -C pacman
	# make clean -C nibbler
		@echo "Clean faite!"

fclean: clean
	make clean fclean -C snake
	make clean fclean -C pacman
	# make clean fclean -C nibbler
		@echo "FClean faite!"

re:	fclean all
		@echo "Re fait!"

tests_run:
	make -C snake/tests/
	make -C pacman/tests/
	# make -C nibbler/tests/

.PHONY: clean fclean re all tests_run pacman snake nibbler
