#include "helper.h"

i32	tester_pipe_stdout(i8 *target_file)
{
	i32	usr_out;
	i32	std_out;

	fflush(stdout);
	usr_out = open(target_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (usr_out < 0)
		return (-1);
	std_out = dup(STDOUT_FILENO);
	if (std_out < 0)
		return (-1);
	if (dup2(usr_out, STDOUT_FILENO) < 0)
		return (-1);
	close(usr_out);
	return (std_out);
}

void	tester_reset_stdout(i32 std_out_fd)
{
	fflush(stdout);
	dup2(std_out_fd, STDOUT_FILENO);
}

void	ft_tester_set_title(i8 *title)
{
	tester_putstr(BOLD BLUE ITALIC "\n\n");
	tester_putstr(title);
	tester_putstr(" :\n" RESET);
	tester_putstr("     ");
}

void	ft_tester_set_sub_title(i8 *category)
{
	tester_putstr(BOLD CYAN "\n\n     category '");
	tester_putstr(category);
	tester_putstr("' :\n" RESET);
	tester_putstr("     ");
}

void	tester_putnbr(i64 num)
{
	if (num < 0)
	{
		tester_putstr("-");
		num *= -1;
	}
	if (num >= 10)
	{
		tester_putnbr(num / 10);
		tester_putnbr(num % 10);
	}
	if (num < 10)
		tester_putchar(num + 48);
}
