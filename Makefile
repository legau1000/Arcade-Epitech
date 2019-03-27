##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

all:
	make -C core
	make -C games
	make -C lib

core:
	make -C core/

games:
	make -C games

graphicals:
	make -C lib

clean:
	make clean -C core
	make clean -C games
	make clean -C lib
		@echo "Clean faite!"

fclean: clean
	make fclean -C core
	make fclean -C games
	make fclean -C lib
		@echo "FClean faite!"

re:	fclean all
		@echo "Re fait!"

tests_run:
	make -C core/tests/
	make -C games/tests/
	make -C lib/tests/

.PHONY: all core games graphicals clean fclean re tests_run
