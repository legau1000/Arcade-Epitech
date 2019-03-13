##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

CXXFLAGS	=	-Iinclude -I../ -ILib/include -IGraphical/include -W -Wall -Wextra -Wshadow

LDFLAGS		=	-l c_graph_prog -LLib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

RM	=	rm

SRC_BASE	=	src/

SRC_FILES	=	main.cpp \
	InitWindow.cpp

SRC		=	$(addprefix $(SRC_BASE),$(SRC_FILES))

OBJ	=	$(SRC:.cpp=.o)

NAME	=	 lib_arcade_sfml

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
