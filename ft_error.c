#include "tester.h"

static void	ft_error_handler(i32 signal_num)
{
	if (signal_num == SIGSEGV)
		tester_putstr(BOLD RED "SIGSEGV" RESET);
	else if (signal_num == SIGKILL)
		tester_putstr(BOLD RED "TIMEOUT" RESET);
	else if (signal_num == SIGILL)
		tester_putstr(BOLD RED "FORBIDDEN" RESET);
	else
		tester_putstr(BOLD RED "CRASH" RESET);
}

void	ft_handle_error(void)
{
	signal(SIGSEGV, ft_error_handler);
	signal(SIGKILL, ft_error_handler);
	signal(SIGILL, ft_error_handler);
}
