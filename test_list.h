#ifndef TEST_LIST_H
# define TEST_LIST_H
# include "helper.h"
# include "tester.h"

typedef struct s_test
{
	int				id;
	int				error;
	t_output		or_out;
	t_output		ft_out;
	char			*caller;
	struct s_test	*next;
}					t_test;

t_test				*ft_init_test(t_test *test);
t_test				*ft_create_test(int id, t_output or_out, t_output ft_out,
						char *caller);
void				ft_push_test(t_test **test, t_test *nw);
void				ft_clear_test(t_test **test);
void				ft_eject_test(t_test *test);
#endif