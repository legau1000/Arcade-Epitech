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
	$(RM) -f $(OBJ)
		@echo "Clean faite!"

fclean: clean
	$(RM) -f $(NAME)
		@echo "FClean faite!"

re:	fclean all
		@echo "Re fait!"

tests_run:
	make -C core/tests/
	make -C Games/tests/
	make -C lib/tests/

.PHONY: clean fclean re all tests_run
