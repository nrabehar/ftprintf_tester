#include "tester.h"

i32			g_test_number;
i32			g_total_test;
i32			g_test_success;
void	ft_run_test(i32 or_res, i32 ft_res, i8 *params)
{
	t_data	data;

	++g_total_test;
	data = init_data(g_test_number, or_res, ft_res, params);
	data.ft_cnt = get_file_content(FT_OUT_FILE);
	if (!data.ft_cnt)
		return ;
	data.or_cnt = get_file_content(OR_OUT_FILE);
	if (!data.or_cnt)
		return (free(data.ft_cnt));
	if (ft_validate(&data))
	{
		print_success(g_test_number);
		g_test_success++;
	}
	else
	{
		print_error(params, g_test_number, data.or_cnt, data.ft_cnt,
			data.or_res, data.ft_res);
	}
	ft_tester_clear_data(&data);
	g_test_number++;
	usleep(12000);
}

static void	ft_parse_param(i8 *ac[])
{
	if (!ac)
		return ;
	tester_test_all();
}

i32	main(i32 av, i8 *ac[])
{
	ft_handle_error();
	g_test_number = 0;
	g_total_test = 0;
	g_test_success = 0;
	if (!ac[1] || tester_strcmp(ac[1], "__tx_nrb__ft") != 0)
	{
		return (tester_putstr(BOLD RED "\nPlease read the README.md file before.\n" RESET),
			EXIT_FAILURE);
	}
	if (av < 3)
		tester_test_all();
	else
		ft_parse_param(ac);
	tester_putstr(GRAY "\n\nNumber of success tests : ");
	if (g_test_success >= g_total_test / 3)
		tester_putstr(BLUE);
	if (g_test_success >= g_total_test / 2)
		tester_putstr(GREEN);
	if (g_test_success < g_total_test / 3)
		tester_putstr(RED);
	tester_putnbr(g_test_success);
	tester_putstr(RESET "/");
	tester_putnbr(g_total_test);
	tester_putstr("\n");
	return (0);
}
