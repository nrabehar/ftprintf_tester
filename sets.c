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
	return ;
}

void	tester_test_all(void)
{
	ft_test_mandatory();
	ft_test_bonus_v1();
}
