#include "tester.h"

static void	ft_error_handler(i32 signal_num)
{
	/* invalid access to storage */
	if (signal_num == SIGSEGV)
		ft_tester_putstr(BOLD RED "SIGSEGV" RESET);
	else if (signal_num == SIGKILL)
		ft_tester_putstr(BOLD RED "TIMEOUT" RESET);
	else if (signal_num == SIGILL)
		ft_tester_putstr(BOLD RED "FORBIDDEN" RESET);
	else
		ft_tester_putstr(BOLD RED "CRASH" RESET);
	signal(signal_num, ft_error_handler);
}

void	ft_handle_error(void)
{
	signal(SIGSEGV, ft_error_handler);
	signal(SIGKILL, ft_error_handler);
	signal(SIGILL, ft_error_handler);
}
