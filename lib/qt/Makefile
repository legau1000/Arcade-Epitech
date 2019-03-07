##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

RM		=	rm -f

NAME	=	 lib_arcade_qt.so

.SILENT:

all:
	make -C src/

clean:
	$(RM) src/*.o

fclean: clean
	$(RM) -f $(NAME)

re:	fclean all

tests_run:
	make -C tests/

.PHONY: clean tests_run re clean
