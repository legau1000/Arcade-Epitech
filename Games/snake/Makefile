##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

CXXFLAGS	=	-Iinclude -I../ -I./../../lib/ -shared -fPIC

RM	=	rm

SRC_BASE	=	src/

SRC_FILES	=	Snake.cpp

SRC		=	$(addprefix $(SRC_BASE),$(SRC_FILES))

OBJ	=	$(SRC:.cpp=.o)

NAME	=	 ../lib_arcade_snake.so

.SILENT:

$(NAME):	$(OBJ)
	g++ -shared -o $(NAME) $(OBJ) $(CXXFLAGS)

all:	$(NAME)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re:	fclean all

tests_run:
	make -C tests/

.PHONY: clean tests_run re clean
