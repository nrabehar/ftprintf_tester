#include "helper.h"

static void	print_res_pad(i8 *or_cnt, i8 *ft_cnt, ui64 result, bool is_or)
{
	ui64	or_len;
	ui64	ft_len;
	ui64	i;
	ui64	len;

	or_len = tester_strlen(or_cnt);
	ft_len = tester_strlen(ft_cnt);
	if (or_len > ft_len)
		len = or_len - ft_len;
	else
		len = ft_len - or_len;
	tester_putstr("]    ");
	i = 0;
	while (i < len)
	{
		if (is_or && ft_len > result)
			tester_putchar(' ');
		else if (!is_or && or_len > result)
			tester_putchar(' ');
		i++;
	}
	tester_putstr("| Result : ");
}

void	print_diff(i8 *or_cnt, i8 *ft_cnt, i32 or_res, i32 ft_res)
{
	ui64	i;
	ui64	or_len;

	tester_putstr("Excepted  :   [");
	tester_puts_no_printable(or_cnt);
	print_res_pad(or_cnt, ft_cnt, or_res, true);
	tester_putnbr(or_res);
	tester_putstr("\nGOT       :   [");
	i = 0;
	or_len = tester_strlen(or_cnt);
	while (ft_cnt[i])
	{
		if (i < or_len && or_cnt[i] != ft_cnt[i])
			tester_putstr(RED);
		else if (i > or_len)
			tester_putstr(RED);
		tester_putc_no_printable(ft_cnt[i]);
		tester_putstr(RESET);
		i++;
	}
	print_res_pad(or_cnt, ft_cnt, ft_res, false);
	tester_putstr(BOLD RED);
	tester_putnbr(ft_res);
	tester_putstr(RESET "\n");
}

void	print_error(i8 *caller, i32 test_n)
{
	tester_putstr(RED "[");
	tester_putnbr(test_n);
	tester_putstr(" KO]\n" RESET);
	tester_putstr("Test will called like that : ");
	tester_putstr(BLUE "ft_printf");
	tester_putstr(caller);
	tester_putstr(RESET ";\n");
}

void	print_success(i32 test_n)
{
	tester_putstr(GREEN "[");
	tester_putnbr(test_n);
	tester_putstr(" OK] " RESET);
}
