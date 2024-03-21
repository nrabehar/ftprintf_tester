#ifndef TESTER_H
# define TESTER_H

# ifndef FT_OUT_FILE
#  define FT_OUT_FILE "out/ft.out"
# endif
# ifndef OR_OUT_FILE
#  define OR_OUT_FILE "out/or.out"
# endif

# include "helper/helper.h"
# include "sets.h"
# include "libftprintf.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>

# define TEST(params)                              \
	do                                            \
	{                                             \
		i32 std_fd;                               \
		i32 or_res;                               \
		i32 ft_res;                               \
		std_fd = tester_pipe_stdout(OR_OUT_FILE); \
		or_res = printf params;                   \
		tester_reset_stdout(std_fd);              \
		std_fd = tester_pipe_stdout(FT_OUT_FILE); \
		ft_res = ft_printf params;                \
		tester_reset_stdout(std_fd);              \
		ft_run_test(or_res, ft_res, #params);     \
	} while (0)

void	ft_handle_error(void);
void	ft_run_test(i32 or_res, i32 ft_res, i8 *params);

#endif