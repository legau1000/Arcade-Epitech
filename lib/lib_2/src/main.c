/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"
#include "def.h"

int main(int ac, char **av)
{
	if (errors(ac, av) == 84)
		return (84);
	printf("%s\n%d\n%s\n%s\n", FILE, LINE, TIME, DATE);
	return (0);
}
