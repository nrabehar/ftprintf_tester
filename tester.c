#include "sets.h"
#include "tester.h"
#include <stdio.h>
#include <unistd.h>

i32		g_test_number;
void	ft_run_test(i32 or_res, i32 ft_res, i8 *params)
{
	t_data	data;

	data = ft_tester_get_data(g_test_number, or_res, ft_res, params);
	data.ft_cnt = get_tester_file_content(FT_OUT_FILE);
	data.or_cnt = get_tester_file_content(OR_OUT_FILE);
	if (!ft_validate(&data))
	{
		ft_tester_putstr(RED "[KO]" RESET);
		// todo : stock error data
	}
	else
	{
		ft_tester_putstr(GREEN "[OK]" RESET);
	}
	ft_tester_clear_data(&data);
	g_test_number++;
}

int	main(void)
{
	ft_handle_error();
	g_test_number = 0;
	test_c_simple();
	test_s_simple();
	test_x_b1();
	return (0);
}
