##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

CC				=	g++

CXXFLAGS		=	-Iinclude -I../ -shared -fPIC

RM				=	rm

SRC				=	src/Caca.cpp

OBJ				= 	$(SRC:.cpp=.o)

NAME			=	 ../lib_arcade_caca.so # ../

# .SILENT:

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) `pkg-config --libs --cflags caca` -shared -o $(NAME) $(OBJ)

clean:
				$(RM) -f $(OBJ)

fclean: 		clean
				$(RM) -f $(NAME)

re:				fclean all

tests_run:
				make -C tests/

.PHONY: 		clean tests_run re clean