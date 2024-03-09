#include "test_list.h"
#include "tester.h"
#include <stdio.h>

int			std_fd = 0;
t_output	usr_out;
t_output	org_out;
t_test    *g_test;
char		*caller;
int			test_nb = 0;

static void parse_av(int ac, char *av[])
{
  int i;
  int tested;
  
  i = 1;
  tested = 0;
  while (i < ac)
  {
    if (strcmp(av[i], "c") == 0)
    {
      test_c_simple();
      tested++;
    }
    if (strcmp(av[i], "s") == 0)
    {
      test_s_simple();
      tested++;
    }
    i++;
  }
  if (tested == 0)
    test_x_b1();
}

int	main(int ac, char *av[])
{
  if(ac == 1)
  {
    test_c_simple();
    test_s_simple();
    test_x_b1();
    return (0);
  }
  parse_av(ac, av);
	return (0);
}
