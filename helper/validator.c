#include "helper.h"

static bool	check_content_diff(t_data *data)
{
  ui64 len;

  len = ft_tester_strlen(data->or_cnt);
	if (ft_tester_memcmp(data->or_cnt, data->ft_cnt, len) == 0)
		return (false);
	return (true);
}

static bool	check_result_diff(t_data *data)
{
	if (data->or_res == data->ft_res)
		return (false);
	return (true);
}

bool	ft_validate(t_data *data)
{
	if (!data->or_cnt)
		if (data->ft_cnt)
			return (false);
	if (!data->ft_cnt)
		return (true);
	if (check_result_diff(data) || check_content_diff(data))
		return (false);
	return (true);
}
