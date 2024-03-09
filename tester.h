#ifndef TESTER_H
# define TESTER_H

# ifndef USER_OUTPUT_FILE
#  define USER_OUTPUT_FILE "out/user.out"
# endif
# ifndef SYS_OUTPUT_FILE
#  define SYS_OUTPUT_FILE "out/sys.out"
# endif

# include "helper.h"
# include "libftprintf.h"
# include "test_list.h"
# include "tests.h"

# define TEST(fmt, ...)                                    \
	test_nb++;                                            \
	std_fd = pipe_stdout(USER_OUTPUT_FILE);               \
	usr_out.result = ft_printf(fmt, __VA_ARGS__);            \
	reset_stdout(std_fd);                                 \
	std_fd = pipe_stdout(SYS_OUTPUT_FILE);                \
	org_out.result = printf(fmt, __VA_ARGS__);            \
	reset_stdout(std_fd);                                 \
	org_out.content = get_file_content(SYS_OUTPUT_FILE);  \
	usr_out.content = get_file_content(USER_OUTPUT_FILE); \
	check(org_out, usr_out);                              \
	//ft_push_test(&g_test, ft_create_test(test_nb, org_out, usr_out, caller));

int	check(t_output or_out, t_output ft_out);
int	check_result(char *, char *or_file, char *ft_file);

#endif