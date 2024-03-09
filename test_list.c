#include "test_list.h"

t_test	*ft_init_test(t_test *test)
{
  printf("\nInit\n");
	test = NULL;
	return (test);
}

t_test	*ft_create_test(int id, t_output or_out, t_output ft_out, char *caller)
{
	t_test	*test;

	test = malloc(sizeof(t_test));
	if (!test)
		return (NULL);
	test->ft_out = ft_out;
	test->or_out = or_out;
	test->error = diff(or_out.content, ft_out.content, strlen(or_out.content));
	test->id = id;
	test->caller = caller;
	test->next = NULL;
	return (test);
}

void	ft_push_test(t_test **test, t_test *nw)
{
	t_test	*tmp;

	tmp = *test;
	if (*test == NULL || !test)
	{
		*test = nw;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = nw;
}

void	ft_clear_test(t_test **test)
{
	if (!*test || !test)
		return ;
	if ((*test)->next)
		ft_clear_test(&(*test)->next);
	printf("\nclearing test N° %d\n", (*test)->id);
	free((*test)->caller);
	free(*test);
	*test = NULL;
}

void	ft_eject_test(t_test *test)
{
	ft_clear_test(&test);
	remove(USER_OUTPUT_FILE);
	remove(SYS_OUTPUT_FILE);
}