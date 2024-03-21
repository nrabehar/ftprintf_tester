#include "sets.h"

extern int	g_test_number;

void	tester_test_c_simple(void)
{
	g_test_number = 0;
	ft_tester_set_title(" - simple c");
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
	char	*null_char;

	null_char = NULL;
	g_test_number = 0;
	ft_tester_set_title(" - simple s");
	TEST(("%s", ""));
	TEST(("%s", null_char));
	TEST(("%s", "some string with %s hehe");
	TEST((" %s", "can it handle \t and \n?"));
	TEST(("%sx", "{} al$#@@@^&$$^#^@@^$*((&")));
	TEST(("%s%s%s", "And ", "some", "joined"));
	TEST(("%ss%ss%ss", "And ", "some other", "joined"));
}

void	tester_test_p_simple(void)
{
	g_test_number = 0;
	ft_tester_set_title(" - simple p");
	TEST(("%p", ""));
	TEST(("%p", NULL));
	TEST(("%p", (void *)-14523));
	TEST(("0x%p-", (void *)ULONG_MAX));
	TEST(("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX));
}

void	tester_test_d_simple(void)
{
	g_test_number = 0;
	ft_tester_set_title(" - simple d");
	TEST(("%d", 0));
	TEST(("%d", -10));
	TEST(("%d", -200000));
	TEST(("%d", -6000023));
	TEST(("%d", 10));
	TEST(("%d", 10000));
	TEST(("%d", 100023));
	TEST(("%d", INT_MAX));
	TEST(("%d", INT_MIN));
	TEST(("dgs%dxx", 10));
	TEST(("%d%dd%d", 1, 2, -3));
}

void	tester_test_i_simple(void)
{
	g_test_number = 0;
	ft_tester_set_title(" - simple i");
	TEST(("%i", 0));
	TEST(("%i", -10));
	TEST(("%i", -200000));
	TEST(("%i", -6000023));
	TEST(("%i", 10));
	TEST(("%i", 10000));
	TEST(("%i", 100023));
	TEST(("%i", INT_MAX));
	TEST(("%i", INT_MIN));
	TEST(("dgs%ixx", 10));
	TEST(("%i%id%i", 1, 2, -3));
}

void	tester_test_u_simple(void)
{
	g_test_number = 0;
	ft_tester_set_title(" - simple u");
	TEST(("%u", 0));
	TEST(("%u", -10));
	TEST(("%u", -200000));
	TEST(("%u", -6000023));
	TEST(("%u", 10));
	TEST(("%u", 10000));
	TEST(("%u", 100023));
	TEST(("%u", INT_MAX));
	TEST(("%u", INT_MIN));
	TEST(("%u", UINT_MAX));
	TEST(("dgs%uxx", 10));
	TEST(("%u%ud%u", 1, 2, -3));
}

void	tester_test_x_simple(void)
{
	g_test_number = 0;
	ft_tester_set_title(" - simple x");
	TEST(("%x", 0));
	TEST(("%x", -10));
	TEST(("%x", -200000));
	TEST(("%x", -6000023));
	TEST(("%x", 10));
	TEST(("%x", 10000));
	TEST(("%x", 100023));
	TEST(("%x", 0xabcdef));
	TEST(("%x", 0x7fedcba1));
	TEST(("%x", INT_MAX));
	TEST(("%x", INT_MIN));
	TEST(("%x", UINT_MAX));
	TEST(("dgs%xxx", 10));
	TEST(("%x%xx%x", 1, 2, -3));
}

void	tester_test_X_simple(void)
{
	g_test_number = 0;
	ft_tester_set_title(" - simple X");
	TEST(("%X", 0));
	TEST(("%X", -10));
	TEST(("%X", -200000));
	TEST(("%X", -6000023));
	TEST(("%X", 10));
	TEST(("%X", 10000));
	TEST(("%X", 100023));
	TEST(("%X", 0xabcdef));
	TEST(("%X", 0x7fedcba1));
	TEST(("%X", INT_MAX));
	TEST(("%X", INT_MIN));
	TEST(("%X", UINT_MAX));
	TEST(("dgs%Xxx", 10));
	TEST(("%X%Xx%X", 1, 2, -3));
}

void	tester_test_x_b1(void)
{
	g_test_number = 0;
	ft_tester_set_title(" - b1 x");
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

void	ft_test_mandatory(void)
{
	ft_tester_set_title(RESET BOLD CYAN "\nMandatory ");
	tester_test_c_simple();
	tester_test_s_simple();
	tester_test_p_simple();
	tester_test_d_simple();
	tester_test_i_simple();
	tester_test_u_simple();
	tester_test_x_simple();
	tester_test_X_simple();
}

void	ft_test_bonus_v1(void)
{
	ft_tester_set_title(RESET BOLD CYAN "\nBonus v1 ");
	tester_test_x_b1();
	return ;
}

void	tester_test_all(void)
{
	ft_test_mandatory();
	ft_test_bonus_v1();
}