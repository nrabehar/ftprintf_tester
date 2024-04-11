#include "sets.h"

extern int	g_test_number;

void	tester_test_no_flags(void)
{
	g_test_number = 0;
	ft_tester_set_title(" - no category");
	TEST(("Hello"));
}

void	tester_test_c_simple(void)
{
	g_test_number = 0;
	ft_tester_set_title(" - simple c");
	TEST(("%c", 'a'));
	TEST(("%c", '\n'));
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
	g_test_number -= 4;
	TEST(("%s", "some string with %s hehe"); TEST((" %s",
				"can it handle \t and \n?")); TEST(("%sx",
				"{} al$#@@@^&$$^#^@@^$*((&")));
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

void	tester_test_mix_simple(void)
{
	int			value1;
	int			value2;
	int			value3;
	int			value4;
	int			value5;
	int			*ptr1;
	int			*ptr2;
	int			*ptr3;
	int			*ptr4;
	int			*ptr5;
	int			*ptr6;
	int			*ptr7;
	int			*null_ptr;
	char		char1;
	char		char2;
	const char	*str1 = "Hello";
	const char	*str2 = "World";
	const char	*empty_str = "";

	// Définit quelques variables pour les tests.
	value1 = 42;
	value2 = -100;
	value3 = 123456;
	value4 = 789;
	value5 = -789;
	int value6 = 2147483647;  // INT_MAX
	int value7 = -2147483648; // INT_MIN
	ptr1 = &value1;
	ptr2 = &value2;
	ptr3 = &value3;
	ptr4 = &value4;
	ptr5 = &value5;
	ptr6 = &value6;
	ptr7 = &value7;
	null_ptr = NULL;
	char1 = 'A';
	char2 = 'z';
	ft_tester_set_title(" - simple mix");
	ft_tester_set_sub_title("c, s, d");
	g_test_number = 0;
	TEST(("%c %s %d", 'A', "Hello", 42));
	TEST(("%c %s %d", 'z', "World", -100));
	TEST(("%c %s %d", 'B', "", 789));
	TEST(("%c %s %d", 'X', "Test", -2147483648));  // INT_MIN
	TEST(("%c %s %d", 'M', "OpenAI", 2147483647)); // INT_MAX
	TEST(("%c %s %d", 'a', "abc", 123456));
	TEST(("%c %s %d", 'T', "Test", -789));
	TEST(("%c %s %d", 'k', "test string", 56));
	TEST(("%c %s %d", '\0', "NullChar", 78));
	TEST(("%c %s %d", 'm', "Mchar", 999));
	ft_tester_set_sub_title("c, p, d");
	g_test_number = 0;
	TEST(("%c %p %d", 'A', &value1, value1));
	TEST(("%c %p %d", 'B', &value2, value2));
	TEST(("%c %p %d", 'C', &value3, value3));
	TEST(("%c %p %d", 'D', &value4, value4));
	TEST(("%c %p %d", 'E', &value5, value5));
	TEST(("%c %p %d", 'F', &value6, value6));
	TEST(("%c %p %d", 'G', &value7, value7));
	TEST(("%c %p %d", 'H', null_ptr, 0));
	TEST(("%c %p %d", 'I', (void *)0xDEADBEEF, 100));
	TEST(("%c %p %d", 'J', (void *)0xCAFEBABE, 200));
	ft_tester_set_sub_title("s, i, u");
	g_test_number = 0;
	TEST(("%s %i %u", "Hello", 42, 100));
	TEST(("%s %i %u", "World", -100, 200));
	TEST(("%s %i %u", "", 789, 300));
	TEST(("%s %i %u", "Test", -2147483648, 400));  // INT_MIN
	TEST(("%s %i %u", "OpenAI", 2147483647, 500)); // INT_MAX
	TEST(("%s %i %u", "abc", 123456, 600));
	TEST(("%s %i %u", "def", -789, 700));
	TEST(("%s %i %u", "test string", 56, 800));
	TEST(("%s %i %u", "string", 78, 900));
	TEST(("%s %i %u", "sample", 999, 1000));
	ft_tester_set_sub_title("s, x, X");
	g_test_number = 0;
	TEST(("%s %x %X", "Hello", 42, 100));
	TEST(("%s %x %X", "World", -100, 200));
	TEST(("%s %x %X", "", 789, 300));
	TEST(("%s %x %X", "Test", -2147483648, 400));  // INT_MIN
	TEST(("%s %x %X", "OpenAI", 2147483647, 500)); // INT_MAX
	TEST(("%s %x %X", "abc", 123456, 600));
	TEST(("%s %x %X", "def", -789, 700));
	TEST(("%s %x %X", "test string", 56, 800));
	TEST(("%s %x %X", "string", 78, 900));
	TEST(("%s %x %X", "sample", 999, 1000));
	ft_tester_set_sub_title("p, u, %");
	g_test_number = 0;
	TEST(("%p %u %%", ptr1, 100));
	TEST(("%p %u %%", ptr2, 200));
	TEST(("%p %u %%", ptr3, 300));
	TEST(("%p %u %%", ptr4, 400));
	TEST(("%p %u %%", ptr5, 500));
	TEST(("%p %u %%", ptr6, 600));
	TEST(("%p %u %%", ptr7, 700));
	TEST(("%p %u %%", null_ptr, 800));
	TEST(("%p %u %%", (void *)0xDEADBEEF, 900));
	TEST(("%p %u %%", (void *)0xCAFEBABE, 1000));
	ft_tester_set_sub_title("c, d, x");
	g_test_number = 0;
	TEST(("%c %d %x", 'A', 42, 0x2A));
	// 42 en hexadécimal
	TEST(("%c %d %x", 'B', -100, 0xFFFFFF9C));
	TEST(("%c %d %x", 'C', 123456,
			0x1E240)); // 123456 en hexadécimal
	TEST(("%c %d %x", 'D', -2147483648,
			0x80000000)); // INT_MIN en hexadécimal
	TEST(("%c %d %x", 'E', 2147483647,
			0x7FFFFFFF)); // INT_MAX en hexadécimal
	TEST(("%c %d %x", 'F', -789, 0xFFFFFF1B));
	TEST(("%c %d %x", 'G', 789, 0x315)); // 789 en hexadécimal
	TEST(("%c %d %x", 'H', 56, 0x38));   // 56 en hexadécimal
	TEST(("%c %d %x", 'I', 78, 0x4E));   // 78 en hexadécimal
	TEST(("%c %d %x", 'J', 999, 0x3E7)); // 999 en hexadécimal
	ft_tester_set_sub_title("c, s, %");
	g_test_number = 0;
	TEST(("%c %s %%", 'A', "Hello"));
	TEST(("%c %s %%", 'B', "World"));
	TEST(("%c %s %%", 'C', ""));
	TEST(("%c %s %%", 'D', "Test"));
	TEST(("%c %s %%", 'E', "OpenAI"));
	TEST(("%c %s %%", 'F', "abc"));
	TEST(("%c %s %%", 'G', "test string"));
	TEST(("%c %s %%", 'H', "string"));
	TEST(("%c %s %%", 'I', "sample"));
	TEST(("%c %s %%", 'J', "example"));
	ft_tester_set_sub_title("i, x, u");
	g_test_number = 0;
	TEST(("%i %x %u", 42, 0x2A, 100));
	TEST(("%i %x %u", -100, 0xFFFFFF9C, 200));
	TEST(("%i %x %u", 123456, 0x1E240, 300));
	TEST(("%i %x %u", -2147483648, 0x80000000, 400)); // INT_MIN en hexadécimal
	TEST(("%i %x %u", 2147483647, 0x7FFFFFFF, 500));  // INT_MAX en hexadécimal
	TEST(("%i %x %u", -789, 0xFFFFFF1B, 600));
	TEST(("%i %x %u", 789, 0x315, 700));
	TEST(("%i %x %u", 56, 0x38, 800));
	TEST(("%i %x %u", 78, 0x4E, 900));
	TEST(("%i %x %u", 999, 0x3E7, 1000));
}

void	tester_test_c_b1(void)
{
	ft_tester_set_title(" - b1 c");
	ft_tester_set_sub_title(".");
	g_test_number = 0;
	TEST(("%-c", 'a'));
	TEST(("%-c", 'z'));
	TEST(("%-c", 'A'));
	TEST(("%-c", 'Z'));
	TEST(("%-c", '0'));
	TEST(("%-c", '9'));
	TEST(("%-c", '\n'));
	TEST(("%-c", '\t'));
	TEST(("%-c", ' '));
	ft_tester_set_sub_title("width");
	g_test_number = 0;
	TEST(("%5c", 'a'));
	TEST(("%5c", 'z'));
	TEST(("%5c", 'A'));
	TEST(("%5c", 'Z'));
	TEST(("%5c", '0'));
	TEST(("%5c", '9'));
	TEST(("%5c", '\n'));
	TEST(("%5c", '\t'));
	TEST(("%5c", ' '));
	ft_tester_set_sub_title("width,.");
	g_test_number = 0;
	TEST(("%-5c", 'a'));
	TEST(("%-5c", 'z'));
	TEST(("%-5c", 'A'));
	TEST(("%-5c", 'Z'));
	TEST(("%-5c", '0'));
	TEST(("%-5c", '9'));
	TEST(("%-5c", '\n'));
	TEST(("%-5c", '\t'));
	TEST(("%-5c", ' '));
}

void	tester_test_s_b1(void)
{
	char	*null_str;

	null_str = NULL;
	ft_tester_set_title(" - b1 s");
	ft_tester_set_sub_title(".");
	g_test_number = 0;
	TEST(("%-s", null_str));
	TEST(("%-s", "Hello"));
	TEST(("%-s", "42"));
	TEST(("%-s", "This is a longer test string"));
	TEST(("%-s", "Single"));
	TEST(("%-s", "Multiple\nLines\nString"));
	ft_tester_set_sub_title("width");
	g_test_number = 0;
	TEST(("%15s", null_str));
	TEST(("%15s", "Hello"));
	TEST(("%15s", "42"));
	TEST(("%15s", "This is a longer test string"));
	TEST(("%15s", "Single"));
	TEST(("%15s", "Multiple\nLines\nString"));
	ft_tester_set_sub_title("width,.");
	g_test_number = 0;
	TEST(("%-15s", null_str));
	TEST(("%-15s", "Hello"));
	TEST(("%-15s", "42"));
	TEST(("%-15s", "This is a longer test string"));
	TEST(("%-15s", "Single"));
	TEST(("%-15s", "Multiple\nLines\nString"));
	ft_tester_set_sub_title(".");
	g_test_number = 0;
	TEST(("%.5s", null_str));
	TEST(("%.5s", "Hello"));
	TEST(("%.5s", "42"));
	TEST(("%.5s", "This is a longer test string"));
	TEST(("%.5s", "Single"));
	TEST(("%.5s", "Multiple\nLines\nString"));
	ft_tester_set_sub_title("width,.");
	g_test_number = 0;
	TEST(("%15.5s", null_str));
	TEST(("%15.5s", "Hello"));
	TEST(("%15.5s", "42"));
	TEST(("%15.5s", "This is a longer test string"));
	TEST(("%15.5s", "Single"));
	TEST(("%15.5s", "Multiple\nLines\nString"));
	ft_tester_set_sub_title("width,-,.");
	g_test_number = 0;
	TEST(("%-15.5s", null_str));
	TEST(("%-15.5s", "Hello"));
	TEST(("%-15.5s", "42"));
	TEST(("%-15.5s", "This is a longer test string"));
	TEST(("%-15.5s", "Single"));
	TEST(("%-15.5s", "Multiple\nLines\nString"));
}

void	tester_test_d_b1(void)
{
	ft_tester_set_title(" - b1 d");
	ft_tester_set_sub_title("-");
	g_test_number = 0;
	TEST(("%-d", 0));
	TEST(("%-d", 1));
	TEST(("%-d", -1));
	TEST(("%-d", 12345));
	TEST(("%-d", -54321));
	TEST(("%-d", INT_MAX));
	TEST(("%-d", INT_MIN));
	ft_tester_set_sub_title("width");
	g_test_number = 0;
	TEST(("%10d", 0));
	TEST(("%10d", 1));
	TEST(("%10d", -1));
	TEST(("%10d", 12345));
	TEST(("%10d", -54321));
	TEST(("%10d", INT_MAX));
	TEST(("%10d", INT_MIN));
	ft_tester_set_sub_title("width,-");
	g_test_number = 0;
	TEST(("%-10d", 0));
	TEST(("%-10d", 1));
	TEST(("%-10d", -1));
	TEST(("%-10d", 12345));
	TEST(("%-10d", -54321));
	TEST(("%-10d", INT_MAX));
	TEST(("%-10d", INT_MIN));
	ft_tester_set_sub_title(".");
	g_test_number = 0;
	TEST(("%.5d", 0));
	TEST(("%.5d", 1));
	TEST(("%.5d", -1));
	TEST(("%.5d", 12345));
	TEST(("%.5d", -54321));
	TEST(("%.5d", INT_MAX));
	TEST(("%.5d", INT_MIN));
	ft_tester_set_sub_title("width,.");
	g_test_number = 0;
	TEST(("%10.5d", 0));
	TEST(("%10.5d", 1));
	TEST(("%10.5d", -1));
	TEST(("%10.5d", 12345));
	TEST(("%10.5d", -54321));
	TEST(("%10.5d", INT_MAX));
	TEST(("%10.5d", INT_MIN));
	ft_tester_set_sub_title("width,-.");
	g_test_number = 0;
	TEST(("%-10.5d", 0));
	TEST(("%-10.5d", 1));
	TEST(("%-10.5d", -1));
	TEST(("%-10.5d", 12345));
	TEST(("%-10.5d", -54321));
	TEST(("%-10.5d", INT_MAX));
	TEST(("%-10.5d", INT_MIN));
	ft_tester_set_sub_title("0");
	g_test_number = 0;
	TEST(("%010d", 0));
	TEST(("%010d", 1));
	TEST(("%010d", -1));
	TEST(("%010d", 12345));
	TEST(("%010d", -54321));
	TEST(("%010d", INT_MAX));
	TEST(("%010d", INT_MIN));
	ft_tester_set_sub_title("0,width,.");
	g_test_number = 0;
	TEST(("%010.5d", 0));
	TEST(("%010.5d", 1));
	TEST(("%010.5d", -1));
	TEST(("%010.5d", 12345));
	TEST(("%010.5d", -54321));
	TEST(("%010.5d", INT_MAX));
	TEST(("%010.5d", INT_MIN));
}

void	tester_test_i_b1(void)
{
	ft_tester_set_title(" - b1 i");
	ft_tester_set_sub_title("-");
	g_test_number = 0;
	TEST(("%-i", 0));
	TEST(("%-i", 1));
	TEST(("%-i", -1));
	TEST(("%-i", 12345));
	TEST(("%-i", -54321));
	TEST(("%-i", INT_MAX));
	TEST(("%-i", INT_MIN));
	ft_tester_set_sub_title("width");
	g_test_number = 0;
	TEST(("%10i", 0));
	TEST(("%10i", 1));
	TEST(("%10i", -1));
	TEST(("%10i", 12345));
	TEST(("%10i", -54321));
	TEST(("%10i", INT_MAX));
	TEST(("%10i", INT_MIN));
	ft_tester_set_sub_title("width,-");
	g_test_number = 0;
	TEST(("%-10i", 0));
	TEST(("%-10i", 1));
	TEST(("%-10i", -1));
	TEST(("%-10i", 12345));
	TEST(("%-10i", -54321));
	TEST(("%-10i", INT_MAX));
	TEST(("%-10i", INT_MIN));
	ft_tester_set_sub_title(".");
	g_test_number = 0;
	TEST(("%.5i", 0));
	TEST(("%.5i", 1));
	TEST(("%.5i", -1));
	TEST(("%.5i", 12345));
	TEST(("%.5i", -54321));
	TEST(("%.5i", INT_MAX));
	TEST(("%.5i", INT_MIN));
	ft_tester_set_sub_title("width,.");
	g_test_number = 0;
	TEST(("%10.5i", 0));
	TEST(("%10.5i", 1));
	TEST(("%10.5i", -1));
	TEST(("%10.5i", 12345));
	TEST(("%10.5i", -54321));
	TEST(("%10.5i", INT_MAX));
	TEST(("%10.5i", INT_MIN));
	ft_tester_set_sub_title("width,-,.");
	g_test_number = 0;
	TEST(("%-10.5i", 0));
	TEST(("%-10.5i", 1));
	TEST(("%-10.5i", -1));
	TEST(("%-10.5i", 12345));
	TEST(("%-10.5i", -54321));
	TEST(("%-10.5i", INT_MAX));
	TEST(("%-10.5i", INT_MIN));
	ft_tester_set_sub_title("0");
	g_test_number = 0;
	TEST(("%010i", 0));
	TEST(("%010i", 1));
	TEST(("%010i", -1));
	TEST(("%010i", 12345));
	TEST(("%010i", -54321));
	TEST(("%010i", INT_MAX));
	TEST(("%010i", INT_MIN));
	ft_tester_set_sub_title("0,width,.");
	g_test_number = 0;
	TEST(("%010.5i", 0));
	TEST(("%010.5i", 1));
	TEST(("%010.5i", -1));
	TEST(("%010.5i", 12345));
	TEST(("%010.5i", -54321));
	TEST(("%010.5i", INT_MAX));
	TEST(("%010.5i", INT_MIN));
}

void	tester_test_u_b1(void)
{
	ft_tester_set_title(" - b1 u");
	ft_tester_set_sub_title("-");
	g_test_number = 0;
	TEST(("%-u", 0));
	TEST(("%-u", 1));
	TEST(("%-u", 12345));
	TEST(("%-u", UINT_MAX));
	TEST(("%-u", 54321));
	ft_tester_set_sub_title("width");
	g_test_number = 0;
	TEST(("%10u", 0));
	TEST(("%10u", 1));
	TEST(("%10u", 12345));
	TEST(("%10u", UINT_MAX));
	TEST(("%10u", 54321));
	ft_tester_set_sub_title("width,-");
	g_test_number = 0;
	TEST(("%-10u", 0));
	TEST(("%-10u", 1));
	TEST(("%-10u", 12345));
	TEST(("%-10u", UINT_MAX));
	TEST(("%-10u", 54321));
	ft_tester_set_sub_title(".");
	g_test_number = 0;
	TEST(("%.5u", 0));
	TEST(("%.5u", 1));
	TEST(("%.5u", 12345));
	TEST(("%.5u", UINT_MAX));
	TEST(("%.5u", 54321));
	ft_tester_set_sub_title("width,.");
	g_test_number = 0;
	TEST(("%10.5u", 0));
	TEST(("%10.5u", 1));
	TEST(("%10.5u", 12345));
	TEST(("%10.5u", UINT_MAX));
	TEST(("%10.5u", 54321));
	ft_tester_set_sub_title("width,-,.");
	g_test_number = 0;
	TEST(("%-10.5u", 0));
	TEST(("%-10.5u", 1));
	TEST(("%-10.5u", 12345));
	TEST(("%-10.5u", UINT_MAX));
	TEST(("%-10.5u", 54321));
	ft_tester_set_sub_title("0");
	g_test_number = 0;
	TEST(("%010u", 0));
	TEST(("%010u", 1));
	TEST(("%010u", 12345));
	TEST(("%010u", UINT_MAX));
	TEST(("%010u", 54321));
	ft_tester_set_sub_title("0,width,.");
	g_test_number = 0;
	TEST(("%010.5u", 0));
	TEST(("%010.5u", 1));
	TEST(("%010.5u", 12345));
	TEST(("%010.5u", UINT_MAX));
	TEST(("%010.5u", 54321));
}

void	tester_test_x_b1(void)
{
	ft_tester_set_title(" - b1 x");
	ft_tester_set_sub_title(".");
	g_test_number = 0;
	TEST(("%-x", 0));
	TEST(("%-x", 1));
	TEST(("%-x", 255));
	TEST(("%-x", 1024));
	TEST(("%-x", 4096));
	TEST(("%-x", INT_MAX));
	TEST(("%-x", UINT_MAX));
	TEST(("%-x", -1));
	TEST(("%-x", INT_MIN));
	ft_tester_set_sub_title("#");
	g_test_number = 0;
	TEST(("%#x", 0));
	TEST(("%#x", 1));
	TEST(("%#x", 255));
	TEST(("%#x", 1024));
	TEST(("%#x", 4096));
	TEST(("%#x", INT_MAX));
	TEST(("%#x", UINT_MAX));
	TEST(("%#x", -1));
	TEST(("%#x", INT_MIN));
	ft_tester_set_sub_title("0");
	g_test_number = 0;
	TEST(("%0x", 0));
	TEST(("%0x", 1));
	TEST(("%0x", 255));
	TEST(("%0x", 1024));
	TEST(("%0x", 4096));
	TEST(("%0x", INT_MAX));
	TEST(("%0x", UINT_MAX));
	TEST(("%0x", -1));
	TEST(("%0x", INT_MIN));
	ft_tester_set_sub_title("#,0");
	g_test_number = 0;
	TEST(("%#0x", 0));
	TEST(("%#0x", 1));
	TEST(("%#0x", 255));
	TEST(("%#0x", 1024));
	TEST(("%#0x", 4096));
	TEST(("%#0x", INT_MAX));
	TEST(("%#0x", UINT_MAX));
	TEST(("%#0x", -1));
	TEST(("%#0x", INT_MIN));
	ft_tester_set_sub_title("width");
	g_test_number = 0;
	TEST(("%8x", 0));
	TEST(("%8x", 1));
	TEST(("%8x", 255));
	TEST(("%8x", 1024));
	TEST(("%8x", 4096));
	TEST(("%8x", INT_MAX));
	TEST(("%8x", UINT_MAX));
	TEST(("%8x", -1));
	TEST(("%8x", INT_MIN));
	ft_tester_set_sub_title("width,0");
	g_test_number = 0;
	TEST(("%08x", 0));
	TEST(("%08x", 1));
	TEST(("%08x", 255));
	TEST(("%08x", 1024));
	TEST(("%08x", 4096));
	TEST(("%08x", INT_MAX));
	TEST(("%08x", UINT_MAX));
	TEST(("%08x", -1));
	TEST(("%08x", INT_MIN));
	ft_tester_set_sub_title("width,.");
	g_test_number = 0;
	TEST(("%-8x", 0));
	TEST(("%-8x", 1));
	TEST(("%-8x", 255));
	TEST(("%-8x", 1024));
	TEST(("%-8x", 4096));
	TEST(("%-8x", INT_MAX));
	TEST(("%-8x", UINT_MAX));
	TEST(("%-8x", -1));
	TEST(("%-8x", INT_MIN));
}

void	tester_test_X_b1(void)
{
	ft_tester_set_title(" - b1 X");
	ft_tester_set_sub_title("-");
	g_test_number = 0;
	TEST(("%-X", 0));
	TEST(("%-X", 1));
	TEST(("%-X", 255));
	TEST(("%-X", 4096));
	TEST(("%-X", 65535));
	TEST(("%-X", 123456));
	TEST(("%-X", 16777215));
	TEST(("%-X", 0xFFFFFFFF));
	TEST(("%-X", UINT_MAX));
	ft_tester_set_sub_title("width");
	g_test_number = 0;
	TEST(("%10X", 0));
	TEST(("%10X", 1));
	TEST(("%10X", 255));
	TEST(("%10X", 4096));
	TEST(("%10X", 65535));
	TEST(("%10X", 123456));
	TEST(("%10X", 16777215));
	TEST(("%10X", 0xFFFFFFFF));
	TEST(("%10X", UINT_MAX));
	ft_tester_set_sub_title("width,-");
	g_test_number = 0;
	TEST(("%-10X", 0));
	TEST(("%-10X", 1));
	TEST(("%-10X", 255));
	TEST(("%-10X", 4096));
	TEST(("%-10X", 65535));
	TEST(("%-10X", 123456));
	TEST(("%-10X", 16777215));
	TEST(("%-10X", 0xFFFFFFFF));
	TEST(("%-10X", UINT_MAX));
	ft_tester_set_sub_title(".");
	g_test_number = 0;
	TEST(("%.5X", 0));
	TEST(("%.5X", 1));
	TEST(("%.5X", 255));
	TEST(("%.5X", 4096));
	TEST(("%.5X", 65535));
	TEST(("%.5X", 123456));
	TEST(("%.5X", 16777215));
	TEST(("%.5X", 0xFFFFFFFF));
	TEST(("%.5X", UINT_MAX));
	ft_tester_set_sub_title("width,.");
	g_test_number = 0;
	TEST(("%10.5X", 0));
	TEST(("%10.5X", 1));
	TEST(("%10.5X", 255));
	TEST(("%10.5X", 4096));
	TEST(("%10.5X", 65535));
	TEST(("%10.5X", 123456));
	TEST(("%10.5X", 16777215));
	TEST(("%10.5X", 0xFFFFFFFF));
	TEST(("%10.5X", UINT_MAX));
	ft_tester_set_sub_title("width,-,.");
	g_test_number = 0;
	TEST(("%-10.5X", 0));
	TEST(("%-10.5X", 1));
	TEST(("%-10.5X", 255));
	TEST(("%-10.5X", 4096));
	TEST(("%-10.5X", 65535));
	TEST(("%-10.5X", 123456));
	TEST(("%-10.5X", 16777215));
	TEST(("%-10.5X", 0xFFFFFFFF));
	TEST(("%-10.5X", UINT_MAX));
	ft_tester_set_sub_title("0");
	g_test_number = 0;
	TEST(("%010X", 0));
	TEST(("%010X", 1));
	TEST(("%010X", 255));
	TEST(("%010X", 4096));
	TEST(("%010X", 65535));
	TEST(("%010X", 123456));
	TEST(("%010X", 16777215));
	TEST(("%010X", 0xFFFFFFFF));
	TEST(("%010X", UINT_MAX));
	ft_tester_set_sub_title("0,width,.");
	g_test_number = 0;
	TEST(("%010.5X", 0));
	TEST(("%010.5X", 1));
	TEST(("%010.5X", 255));
	TEST(("%010.5X", 4096));
	TEST(("%010.5X", 65535));
	TEST(("%010.5X", 123456));
	TEST(("%010.5X", 16777215));
	TEST(("%010.5X", 0xFFFFFFFF));
	TEST(("%010.5X", UINT_MAX));
}

void	tester_test_p_b1(void)
{
	int	value1;
	int	value2;
	int	value3;
	int	value4;
	int	value5;
	int	*ptr1;
	int	*ptr2;
	int	*ptr3;
	int	*ptr4;
	int	*ptr5;
	int	*ptr6;
	int	*ptr7;
	int	*null_ptr;

	ft_tester_set_title(" - b1 p");
	// Définit des pointeurs pour les tests.
	value1 = 42;
	value2 = -100;
	value3 = 123456;
	value4 = 789;
	value5 = -789;
	int value6 = 2147483647;  // INT_MAX
	int value7 = -2147483648; // INT_MIN
	ptr1 = &value1;
	ptr2 = &value2;
	ptr3 = &value3;
	ptr4 = &value4;
	ptr5 = &value5;
	ptr6 = &value6;
	ptr7 = &value7;
	null_ptr = NULL;
	ft_tester_set_sub_title("-");
	g_test_number = 0;
	TEST(("%-p", null_ptr));
	TEST(("%-p", ptr1));
	TEST(("%-p", ptr2));
	TEST(("%-p", ptr3));
	TEST(("%-p", ptr4));
	TEST(("%-p", ptr5));
	TEST(("%-p", ptr6));
	TEST(("%-p", ptr7));
	TEST(("%-p", (void *)0x12345678));
	TEST(("%-p", (void *)0x9ABCDEF0));
	TEST(("%-p", (void *)0xDEADBEEF));
	ft_tester_set_sub_title("width");
	g_test_number = 0;
	TEST(("%20p", null_ptr));
	TEST(("%20p", ptr1));
	TEST(("%20p", ptr2));
	TEST(("%20p", ptr3));
	TEST(("%20p", ptr4));
	TEST(("%20p", ptr5));
	TEST(("%20p", ptr6));
	TEST(("%20p", ptr7));
	TEST(("%20p", (void *)0x12345678));
	TEST(("%20p", (void *)0x9ABCDEF0));
	TEST(("%20p", (void *)0xDEADBEEF));
	ft_tester_set_sub_title("width,-");
	g_test_number = 0;
	TEST(("%-20p", null_ptr));
	TEST(("%-20p", ptr1));
	TEST(("%-20p", ptr2));
	TEST(("%-20p", ptr3));
	TEST(("%-20p", ptr4));
	TEST(("%-20p", ptr5));
	TEST(("%-20p", ptr6));
	TEST(("%-20p", ptr7));
	TEST(("%-20p", (void *)0x12345678));
	TEST(("%-20p", (void *)0x9ABCDEF0));
	TEST(("%-20p", (void *)0xDEADBEEF));
	ft_tester_set_sub_title(".");
	g_test_number = 0;
	TEST(("%.5p", null_ptr));
	TEST(("%.5p", ptr1));
	TEST(("%.5p", ptr2));
	TEST(("%.5p", ptr3));
	TEST(("%.5p", ptr4));
	TEST(("%.5p", ptr5));
	TEST(("%.5p", ptr6));
	TEST(("%.5p", ptr7));
	TEST(("%.5p", (void *)0x12345678));
	TEST(("%.5p", (void *)0x9ABCDEF0));
	TEST(("%.5p", (void *)0xDEADBEEF));
	ft_tester_set_sub_title("width,.");
	g_test_number = 0;
	TEST(("%20.5p", null_ptr));
	TEST(("%20.5p", ptr1));
	TEST(("%20.5p", ptr2));
	TEST(("%20.5p", ptr3));
	TEST(("%20.5p", ptr4));
	TEST(("%20.5p", ptr5));
	TEST(("%20.5p", ptr6));
	TEST(("%20.5p", ptr7));
	TEST(("%20.5p", (void *)0x12345678));
	TEST(("%20.5p", (void *)0x9ABCDEF0));
	TEST(("%20.5p", (void *)0xDEADBEEF));
}

void	tester_test_mix_b1(void)
{
	int			value1;
	int			value2;
	int			value3;
	int			value4;
	int			value5;
	int			*ptr1;
	int			*ptr2;
	int			*ptr3;
	int			*ptr4;
	int			*ptr5;
	int			*ptr6;
	int			*ptr7;
	int			*null_ptr;
	char		char1;
	char		char2;
	const char	*str1 = "Hello";
	const char	*str2 = "World";
	const char	*empty_str = "";

	// Définit quelques variables pour les tests.
	value1 = 42;
	value2 = -100;
	value3 = 123456;
	value4 = 789;
	value5 = -789;
	int value6 = 2147483647;  // INT_MAX
	int value7 = -2147483648; // INT_MIN
	ptr1 = &value1;
	ptr2 = &value2;
	ptr3 = &value3;
	ptr4 = &value4;
	ptr5 = &value5;
	ptr6 = &value6;
	ptr7 = &value7;
	null_ptr = NULL;
	char1 = 'A';
	char2 = 'z';
	ft_tester_set_title(" - b1 mix");
	ft_tester_set_sub_title("-");
	g_test_number = 0;
	TEST(("%-c %-s %-p %-d %-i %-u %-x %-X %%", 'A', "Hello", &value1, 42, 42,
			42, 42, 42));
	TEST(("%-c %-s %-p %-d %-i %-u %-x %-X %%", 'B', "World", null_ptr, -100,
			-100, 100, 100, 100));
	TEST(("%-c %-s %-p %-d %-i %-u %-x %-X %%", 'C', "Test", ptr2, 789, 789,
			789, 789, 789));
	TEST(("%-c %-s %-p %-d %-i %-u %-x %-X %%", 'D', "OpenAI", ptr3,
			-2147483648, -2147483648, 4294967295, 2147483648, 2147483648));
	TEST(("%-c %-s %-p %-d %-i %-u %-x %-X %%", 'E', "abc", ptr4, 2147483647,
			2147483647, 2147483647, 2147483647, 2147483647));
	TEST(("%-c %-s %-p %-d %-i %-u %-x %-X %%", 'F', "def", ptr5, -789, -789,
			789, 789, 789));
	TEST(("%-c %-s %-p %-d %-i %-u %-x %-X %%", 'G', "test", ptr6, 56, 56, 56,
			56, 56));
	TEST(("%-c %-s %-p %-d %-i %-u %-x %-X %%", 'H', "string", ptr7, 78, 78, 78,
			78, 78));
	TEST(("%-c %-s %-p %-d %-i %-u %-x %-X %%", 'I', "null string", null_ptr, 0,
			0, 0, 0, 0));
	TEST(("%-c %-s %-p %-d %-i %-u %-x %-X %%", 'J', "test string", ptr2, 123,
			123, 123, 123, 123));
	ft_tester_set_sub_title("width");
	g_test_number = 0;
	TEST(("%10c %20s %20p %10d %10i %10u %10x %10X %%", 'A', "Hello", &value1,
			42, 42, 42, 42, 42));
	TEST(("%15c %25s %25p %15d %15i %15u %15x %15X %%", 'B', "World", null_ptr,
			-100, -100, 100, 100, 100));
	TEST(("%20c %30s %30p %20d %20i %20u %20x %20X %%", 'C', "Test", ptr2, 789,
			789, 789, 789, 789));
	TEST(("%25c %35s %35p %25d %25i %25u %25x %25X %%", 'D', "OpenAI", ptr3,
			-2147483648, -2147483648, 4294967295, 2147483648, 2147483648));
	TEST(("%30c %40s %40p %30d %30i %30u %30x %30X %%", 'E', "abc", ptr4,
			2147483647, 2147483647, 2147483647, 2147483647, 2147483647));
	TEST(("%10c %20s %20p %10d %10i %10u %10x %10X %%", 'F', "def", ptr5, -789,
			-789, 789, 789, 789));
	TEST(("%15c %25s %25p %15d %15i %15u %15x %15X %%", 'G', "test", ptr6, 56,
			56, 56, 56, 56));
	TEST(("%20c %30s %30p %20d %20i %20u %20x %20X %%", 'H', "string", ptr7, 78,
			78, 78, 78, 78));
	TEST(("%25c %35s %35p %25d %25i %25u %25x %25X %%", 'I', "null string",
			null_ptr, 0, 0, 0, 0, 0));
	TEST(("%10c %20s %20p %10d %10i %10u %10x %10X %%", 'J', "test string",
			ptr2, 123, 123, 123, 123, 123));
	ft_tester_set_sub_title(".");
	g_test_number = 0;
	TEST(("%.1c %.3s %.5p %.1d %.2i %.2u %.3x %.3X %%", 'A', "Hello", &value1,
			42, 42, 42, 42, 42));
	TEST(("%.1c %.2s %.3p %.1d %.2i %.2u %.3x %.3X %%", 'B', "World", null_ptr,
			-100, -100, 100, 100, 100));
	TEST(("%.1c %.4s %.5p %.3d %.4i %.4u %.5x %.5X %%", 'C', "Test", ptr2, 789,
			789, 789, 789, 789));
	TEST(("%.2c %.5s %.6p %.3d %.3i %.3u %.4x %.4X %%", 'D', "OpenAI", ptr3,
			-2147483648, -2147483648, 4294967295, 2147483648, 2147483648));
	TEST(("%.3c %.6s %.7p %.5d %.4i %.4u %.5x %.5X %%", 'E', "abc", ptr4,
			2147483647, 2147483647, 2147483647, 2147483647, 2147483647));
	TEST(("%.2c %.4s %.3p %.2d %.2i %.2u %.2x %.2X %%", 'F', "def", ptr5, -789,
			-789, 789, 789, 789));
	TEST(("%.1c %.5s %.5p %.1d %.1i %.1u %.3x %.3X %%", 'G', "test", ptr6, 56,
			56, 56, 56, 56));
	TEST(("%.2c %.3s %.2p %.1d %.2i %.2u %.1x %.1X %%", 'H', "string", ptr7, 78,
			78, 78, 78, 78));
	TEST(("%.1c %.4s %.5p %.1d %.1i %.1u %.3x %.3X %%", 'I', "null string",
			null_ptr, 0, 0, 0, 0, 0));
	TEST(("%.3c %.2s %.3p %.4d %.3i %.3u %.3x %.3X %%", 'J', "test string",
			ptr2, 123, 123, 123, 123, 123));
	ft_tester_set_sub_title("- width 0 . #");
	g_test_number = 0;
	TEST(("%-10c %-15s %#-20p %0.5d %.5i %.5u %#.5x %#.5X %%", 'A', "Hello",
			&value1, 42, 42, 42, 42, 42));
	TEST(("%-5c %-10s %-25p %0.10d %.10i %.10u %#.10x %#.10X %%", 'B', "World",
			null_ptr, -100, -100, 100, 100, 100));
	TEST(("%-3c %-5s %0.15p %0.5d %.5i %.5u %.5x %#.5X %%", 'C', "Test", ptr2,
			789, 789, 789, 789, 789));
	TEST(("%-2c %-4s %-10p %.15d %0.10i %0.10u %#.10x %#.10X %%", 'D', "OpenAI",
			ptr3, -2147483648, -2147483648, 4294967295, 2147483648,
			2147483648));
	TEST(("%-3c %-4s %-10p %0.10d %.10i %.10u %#.10x %#.10X %%", 'E', "abc",
			ptr4, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647));
	TEST(("%-5c %-10s %#.15p %.5d %0.5i %0.5u %#.5x %#.5X %%", 'F', "def", ptr5,
			-789, -789, 789, 789, 789));
	TEST(("%-3c %-4s %#.20p %.10d %0.10i %0.10u %#.10x %#.10X %%", 'G', "test",
			ptr6, 56, 56, 56, 56, 56));
	TEST(("%-5c %-5s %#-15p %0.10d %.5i %.5u %#.5x %#.5X %%", 'H', "string",
			ptr7, 78, 78, 78, 78, 78));
	TEST(("%-10c %-10s %-20p %0.10d %.5i %.5u %#.5x %#.5X %%", 'I',
			"null string", null_ptr, 0, 0, 0, 0, 0));
	TEST(("%-10c %-15s %0.20p %0.15d %.10i %.10u %#.10x %#.10X %%", 'J',
			"test string", ptr2, 123, 123, 123, 123, 123));
}

void	ft_test_mandatory(void)
{
	ft_tester_set_title(RESET BOLD CYAN "\nMandatory ");
	tester_test_no_flags();
	tester_test_c_simple();
	tester_test_s_simple();
	tester_test_p_simple();
	tester_test_d_simple();
	tester_test_i_simple();
	tester_test_u_simple();
	tester_test_x_simple();
	tester_test_X_simple();
	tester_test_mix_simple();
}

void	ft_test_bonus_v1(void)
{
	ft_tester_set_title(RESET BOLD CYAN "\nBonus v1 ");
	tester_test_c_b1();
	tester_test_s_b1();
	tester_test_d_b1();
	tester_test_i_b1();
	tester_test_u_b1();
	tester_test_x_b1();
	tester_test_X_b1();
	tester_test_p_b1();
	tester_test_mix_b1();
	return ;
}

void	tester_test_all(void)
{
	ft_test_mandatory();
	ft_test_bonus_v1();
}
