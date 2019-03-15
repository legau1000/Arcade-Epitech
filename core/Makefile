##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

INCLUDE		=	-I ./include -I../games -I../lib -ldl

CXXFLAGS	=	$(INCLUDE) -W -Wall -Wextra -Wshadow 

CXX			=	g++ -g

SRC_BASE	=	src/

SRC_FILES	=	core.cpp	\
				main.cpp

SRC		=	$(addprefix $(SRC_BASE),$(SRC_FILES))

OBJ	=	$(SRC:.cpp=.o)

NAME	=	../arcade

.SILENT:

$(NAME):	clean $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(INCLUDE)
		@echo RE core

all:	$(NAME)

clean:
	rm -f $(OBJ)
		@echo clean core

fclean: clean
	rm -f units_tests
		@echo fclean core

re:	fclean all
		@echo RE core

tests_run:
	make -C tests/

.PHONY: clean fclean re all tests_run