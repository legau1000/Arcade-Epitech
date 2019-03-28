##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

CXXFLAGS	=	-Iinclude -I../ -shared -fPIC -g

RM	=	rm

SRC		=	src/ncurses.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	 ../lib_arcade_ncurses.so

# .SILENT:

$(NAME):	$(OBJ)
	g++ -shared -o $(NAME) $(OBJ) -lncurses

all:	$(NAME)

clean:	$(OBJ)
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re:	fclean all

tests_run:
	make -C tests/

.PHONY: clean tests_run re clean
