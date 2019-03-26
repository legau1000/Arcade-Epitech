##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

all:
	make -C core
	make -C Games
	make -C lib

core:
	make -C re core

games:
	make -C Games

lib:
	make -C lib

clean:
	make clean -C core
	make clean -C Games
	make clean -C lib
		@echo "Clean faite!"

fclean: clean
	make fclean -C core
	make fclean -C Games
	make fclean -C lib
		@echo "FClean faite!"

re:	fclean all
		@echo "Re fait!"

tests_run:
	make -C core/tests/
	make -C Games/tests/
	make -C lib/tests/

.PHONY: clean fclean re all tests_run
