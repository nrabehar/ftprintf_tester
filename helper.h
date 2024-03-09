#ifndef HELPER_H
# define HELPER_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_output
{
	int		result;
	char	*content;
}			t_output;

int			pipe_stdout(char *target_file);
void		reset_stdout(int std_out_fd);
t_output	pipe_result(char *text, char *file, int is_ft);
int			diff(char *excepted, char *result, int max_bytes);
char		*get_file_content(char *file);
char		*generate_caller(char const *format, ...);
void	ft_set_title(char *fmt);

#endif