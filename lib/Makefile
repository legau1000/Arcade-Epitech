##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

.SILENT:

all:
	make -C ncurses
	make -C caca
	make -C sfml

ncurses:
	make -C ncurses

sfml:
	make -C sfml

caca:
	make -C caca

clean:
	make clean -C ncurses
	make clean -C caca
	make clean -C sfml
		@echo "Clean faite!"

fclean: clean
	make fclean -C ncurses
	make fclean -C caca
	make fclean -C sfml
		@echo "FClean faite!"

re:	fclean all
		@echo "Re fait!"

tests_run:
	make -C ncurses/tests/
	make -C caca/tests/
	make -C sfml/tests/

.PHONY: clean fclean re all tests_run
