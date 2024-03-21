#include "tester.h"

i32		g_test_number;
void	ft_run_test(i32 or_res, i32 ft_res, i8 *params)
{
	t_data	data;

	data = init_data(g_test_number, or_res, ft_res, params);
	data.ft_cnt = get_file_content(FT_OUT_FILE);
	data.or_cnt = get_file_content(OR_OUT_FILE);
	if (ft_validate(&data))
		print_success(g_test_number);
	else
	{
		print_error(params, g_test_number);
		print_diff(data.or_cnt, data.ft_cnt, data.or_res, data.ft_res);
	}
	ft_tester_clear_data(&data);
	g_test_number++;
}

static void	ft_parse_param(i8 *ac[])
{
	if (!ac)
		return ;
	tester_test_all();
}

i32	main(i32 av, i8 *ac[])
{
	if (av < 2)
		tester_test_all();
	ft_handle_error();
	g_test_number = 0;
	if (av < 2)
		tester_test_all();
  else
    ft_parse_param(ac);
	return (0);
}
