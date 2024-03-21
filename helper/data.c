#include "helper.h"

t_data	init_data(i32 id, i32 or_res, i32 ft_res, i8 *params)
{
	t_data	data;

	data.id = id;
	data.or_cnt = NULL;
	data.ft_cnt = NULL;
	data.params = params;
	data.or_res = or_res;
	data.ft_res = ft_res;
	return (data);
}

void	ft_tester_clear_data(t_data *data)
{
	if (data->ft_cnt)
		free(data->ft_cnt);
	if (data->or_cnt)
		free(data->or_cnt);
	data->ft_cnt = NULL;
	data->or_cnt = NULL;
}