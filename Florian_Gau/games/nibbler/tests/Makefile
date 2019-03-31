##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

CFLAGS	=	-I../include --coverage

SRC	=	test.c			\
		../src/error/errors.c

OBJ	=	$(SRC:.c=.o)

NAME	=	units_tests

.SILENT:

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcriterion -lgcov
	./units_tests
		@echo Compilation tests faite!

all:	$(NAME)

clean:
	rm -f $(OBJ)
		@echo Clean fait!

fclean: clean
	find ../ -name "*.gcda" -delete
	find ../ -name "*.gcno" -delete
	rm units_tests
		@echo Fclean fait!

re:	fclean all
		@echo RE fait!

.PHONY: clean fclean re all
