#ifndef HELPER_H
# define HELPER_H
# include "colors.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef i8
#  define i8 char
# endif
# define i32 int
# define i64 long
# define ui8 unsigned i8
# define ui32 unsigned i32
# define ui64 unsigned i64

typedef enum bool
{
	false,
	true
}		bool;

typedef struct s_data
{
	i32	id;
	i8	*ft_cnt;
	i8	*or_cnt;
	i8	*params;
	i32	or_res;
	i32	ft_res;
}		t_data;

ui64	ft_tester_strlen(i8 const *str);
void	ft_tester_putstr(i8 const *str);
i32		ft_tester_strcmp(i8 const *s1, i8 const *s2);
i32		ft_tester_memcmp(void *s1, void *s2, i64 len);

i8		*get_tester_file_content(i8 *file);
void	ft_tester_set_title(i8 *title);

t_data	ft_tester_get_data(i32 id, i32 or_res, i32 ft_res, i8 *params);
void	ft_tester_clear_data(t_data *data) ;bool ft_validate(t_data *data);

i32		tester_pipe_stdout(i8 *target_file);
void	tester_reset_stdout(i32 std_out_fd);

#endif // HELPER_H