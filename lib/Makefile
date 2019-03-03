##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

all:
	make -C ncurses
	make -C sfml
	make -C qt

ncurses:
	make -C ncurses

sfml:
	make -C sfml

qt:
	make -C qt

clean:
	make clean -C ncurses
	make clean -C sfml
	make clean -C qt
		@echo "Clean faite!"

fclean: clean
	make fclean -C ncurses
	make fclean -C sfml
	make fclean -C qt
		@echo "FClean faite!"

re:	fclean all
		@echo "Re fait!"

tests_run:
	make -C ncurses/tests/
	make -C sfml/tests/
	make -C qt/tests/

.PHONY: clean fclean re all tests_run
