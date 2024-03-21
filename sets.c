#include "sets.h"

extern int	g_test_number;

void	tester_test_c_simple(void)
{
	g_test_number = 0;
	ft_tester_set_title(" - simple %c");
	TEST(("%c", 'a'));
	TEST(("%c", '\0'));
	TEST(("%c%c", '\0', 'b'));
	TEST(("%c%c", 'a', 'b'));
	TEST(("%c%c%c*", '\0', '1', 1));
	TEST(("%c small string", 'a'));
	TEST(("%c small string", '\0'));
	TEST(("the char is: %c", 'a'));
	TEST(("the char is: %c", '\0'));
	TEST(("n%cs", 'a'));
	TEST(("%c%c%c%c%c", 'a', 'i', 'u', 'e', 'o'));
	TEST(("l%cl%cl%cl%cl%c", 'a', 'i', 'u', 'e', 'o'));
	TEST(("l%cl%cl%cl%cl%c", '\0', '\0', '\0', 'e', '\0'));
}

void	tester_test_s_simple(void)
{
	g_test_number = 0;
	ft_tester_set_title(" - simple %s");
	TEST(("%s", "Hello"));
	TEST(("%s%s", "Hello", "World"));
}

void	tester_test_x_b1(void)
{
	g_test_number = 0;
	ft_tester_set_title(" - bonus_1 %x");
	TEST(("%-#.x", 0));
	TEST(("%-#.x", 1));
	TEST(("%-#.x", -1));
	TEST(("%-#.x", INT_MIN));
	TEST(("%-#.x", INT_MAX));
	TEST(("%-#8.x", 0));
	TEST(("%-#8.x", 1));
	TEST(("%-#8.x", -1));
	TEST(("%-#8.x", INT_MIN));
	TEST(("%-#8.x", INT_MAX));
	TEST(("%-#42x", 0));
	TEST(("%-#42x", 1));
	TEST(("%-#42x", -1));
	TEST(("%-#42x", INT_MIN));
	TEST(("%-#42x", INT_MAX));
	TEST(("%-#42.42x", 0));
	TEST(("%-#42.42x", 1));
	TEST(("%-#42.42x", -1));
	TEST(("%-#42.42x", INT_MIN));
	TEST(("%-#42.42x", INT_MAX));
	TEST(("%-#42.12x", 0));
	TEST(("%-#42.12x", 1));
	TEST(("%-#42.12x", -1));
	TEST(("%-#42.12x", INT_MIN));
	TEST(("%-#42.12x", INT_MAX));
	TEST(("%0#x", 0));
	TEST(("%0#x", 1));
	TEST(("%0#x", -1));
	TEST(("%0#x", INT_MIN));
	TEST(("%0#x", INT_MAX));
	TEST(("%0#42x", 0));
	TEST(("%0#42x", 1));
	TEST(("%0#42x", -1));
	TEST(("%0#42x", INT_MIN));
	TEST(("%0#42x", INT_MAX));
}

void	ft_test_madantory(void)
{
	ft_tester_set_title(RESET BOLD CYAN "\nMadantory ");
	tester_test_c_simple();
	tester_test_s_simple();
}

void	ft_test_bonus_v1(void)
{
	ft_tester_set_title(RESET BOLD CYAN "\nBonus v1 ");
	return ;
}

void	tester_test_all(void)
{
	ft_test_madantory();
	ft_test_bonus_v1();
}