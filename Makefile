##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

INCLUDE		=	-Iinclude

CFLAGS          +=      $(INCLUDE) -W -Wall -Wextra -Wshadow 

CC		=	gcc

RM		=	rm

SRC_BASE	=	src/

SRC_FILES	=	main.c		\
			error/errors.c

SRC		=	$(addprefix $(SRC_BASE),$(SRC_FILES))

OBJ		=	$(SRC:.c=.o)

NAME		=	duo

.SILENT:

$(NAME):	$(OBJ)
	$(CC)  -o $(NAME) $(OBJ)
		@echo "Compilation faite!"

all:	$(NAME)

clean:
	$(RM) -f $(OBJ)
		@echo "Clean faite!"

fclean: clean
	$(RM) -f $(NAME)
		@echo "FClean faite!"

re:	fclean all
		@echo "Re fait!"

tests_run:
	make -C tests/

.PHONY: clean fclean re all tests_run
