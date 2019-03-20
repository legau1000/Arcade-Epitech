##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

CXXFLAGS	=	-Iinclude -Iinclude -I../ -ILib/include

LDFLAGS =  -L./ 

RM	=	rm

SRC_BASE	=	src/

SRC_FILES	=	MapPacman.cpp \
main.cpp

SRC		=	$(addprefix $(SRC_BASE),$(SRC_FILES))

OBJ	=	$(SRC:.cpp=.o)

NAME	=	 pacman

.SILENT:

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS)

all:	$(NAME)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re:	fclean all

tests_run:
	make -C tests/

.PHONY: clean tests_run re clean
