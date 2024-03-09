#include "helper.h"
#include "tester.h"

extern int		test_nb;
extern int		std_fd;
extern t_output	usr_out;
extern t_output	org_out;
extern char		*caller;
extern t_test	*g_test;

void	test_c_simple(void)
{
	ft_set_title("simple %c");
	TEST("%c", 'a');
	TEST("%c", '\0');
	TEST("%c%c", '\0', 'b');
	TEST("%c%c", 'a', 'b');
	TEST("%c%c%c*", '\0', '1', 1);
	TEST("%c small string", 'a');
	TEST("%c small string", '\0');
	TEST("the char is: %c", 'a');
	TEST("the char is: %c", '\0');
	TEST("n%cs", 'a');
	TEST("%c%c%c%c%c", 'a', 'i', 'u', 'e', 'o');
	TEST("l%cl%cl%cl%cl%c", 'a', 'i', 'u', 'e', 'o');
	TEST("l%cl%cl%cl%cl%c", '\0', '\0', '\0', 'e', '\0');
}

void	test_s_simple(void)
{
	ft_set_title("simple %s");
	TEST("%s", "Hello");
	TEST("%s%s", "Hello", "World");
}

void	test_x_b1(void)
{
	ft_set_title("bonus_1 %x");
	TEST("%-#.x", 0);
	TEST("%-#5.x", -1);
}