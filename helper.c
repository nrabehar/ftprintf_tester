#include "colors.h"
#include "helper.h"
#include "test_list.h"

extern int		test_nb;

static size_t	get_file_bytes(char *file)
{
	char	c;
	int		fd;
	size_t	count;

	c = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	count = 0;
	while (read(fd, &c, 1) > 0)
		count++;
	close(fd);
	return (count);
}

char	*get_file_content(char *file)
{
	char	*buffer;
	size_t	bytes;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	bytes = get_file_bytes(file);
	buffer = (char *)malloc(sizeof(char) * (bytes + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, bytes) < 0)
	{
		free(buffer);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (buffer);
}

int	pipe_stdout(char *target_file)
{
	int	usr_out;
	int	std_out;

	fflush(stdout);
	usr_out = open(target_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (usr_out < 0)
		return (-1);
	std_out = dup(STDOUT_FILENO);
	if (std_out < 0)
		return (-1);
	if (dup2(usr_out, STDOUT_FILENO) < 0)
		return (-1);
	close(usr_out);
	return (std_out);
}

char	*generate_caller(char const *format, ...)
{
	char	*fmt;
	char	*buffer;
	char	*params;
	va_list	args;
	size_t	buffer_size;

	fmt = (char *)format;
	buffer_size = 256;
	buffer = (char *)malloc(sizeof(char) * buffer_size);
	params = (char *)malloc(sizeof(char) * buffer_size);
	va_start(args, format);
	strcpy(params, format);
	buffer[0] = '\0';
	strncat(buffer, "ft_printf(" MANGETA, buffer_size - strlen(buffer) - 1);
	strncat(buffer, "\"", buffer_size - strlen(buffer) - 1);
	strncat(buffer, params, strlen(params));
	strncat(buffer, "\"", buffer_size - strlen(buffer) - 1);
	strncat(buffer, RESET ",", buffer_size - strlen(buffer) - 1);
	free(params);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
		}
		else
			fmt++;
	}
	strncat(buffer, ")", buffer_size - strlen(buffer) - 1);
	va_end(args);
	return (buffer);
}

void	reset_stdout(int std_out_fd)
{
	fflush(stdout);
	dup2(std_out_fd, STDOUT_FILENO);
}

int	diff(char *excepted, char *result, int max_bytes)
{
	if (memcmp(excepted, result, max_bytes) == 0)
		return (0);
	return (1);
}

int	check(t_output or_out, t_output ft_out)
{
	if (diff(or_out.content, ft_out.content, or_out.result))
	{
		// todo : store diff | print
		printf(RED " [KO]" RESET);
	}
	else
	{
		// todo : print success
		printf(GREEN " [OK]" RESET);
		remove(USER_OUTPUT_FILE);
		remove(SYS_OUTPUT_FILE);
	}
	free(or_out.content);
	free(ft_out.content);
	return (1);
}
void	ft_set_title(char *fmt)
{
	printf(BOLD BLUE "\nTest for %s%s%s :\n" RESET, ITALIC MANGETA, fmt, RESET);
}

// int	main(void)
// {
// 	char *file1 = "file1.txt";
// 	char *file2 = "file2.txt";
// 	char *text = {"Hello world! This is your echo speaking"};
// 	char *text2 = {"Hello world! This is your speaking"};
// 	printf(BLUE "This is the surrogate shell at work\n" RESET);
// 	printf(BLUE "Echo two different files (%s and %s)\n" RESET, file1, file2);
// 	test(text, file1, file2);
// 	test(text, file1, file2);
// 	test(text, file1, file2);
// 	test(text, file1, file2);
// 	test(text, file1, file2);
// 	printf(GRAY "\nRegular shell output on standard output.\n" RESET);
// 	printf(MANGETA "Please check %s and %s for a special message.\n" RESET,
// 		file1, file2);
// 	return (0);
// }