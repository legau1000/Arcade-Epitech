##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

CXXFLAGS	=	-Iinclude

AR	=	ar rc

RM	=	rm

SRC_BASE	=	src/

SRC_FILES	=	

SRC		=	$(addprefix $(SRC_BASE),$(SRC_FILES))

OBJ	=	$(SRC:.cpp=.o)

NAME	=	 ../lib_arcade_ncurses.so

.SILENT:

$(NAME):	$(OBJ)
	$(AR) -shared -o $(NAME) $(OBJ)

all:	$(NAME)

clean:	$(OBJ)
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re:	fclean all

tests_run:
	make -C tests/

.PHONY: clean tests_run re clean
