/*
** EPITECH PROJECT, 2017
** Test Criterion
** File description:
** bistro-matic
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(errors, simple_string, .init = redirect_all_std)
{
	char *av[] = {"1", "1", "2", "3", "4", "5", "6", "2"};
	int a = 0;

	errors(1, av);
	cr_assert_stdout_eq_str("test\n");
}

Test(simple, test)
{
	char *av[] = {"1", "1", "2", "3", "4", "5", "6", "2"};
	int a = errors(1, av);

	cr_assert(errors(1, av), "test");
	cr_assert((a == 0 || a == 84));
}
