#include "helper.h"

static i64	get_file_bytes(i8 *file)
{
	i8	c;
	i32	fd;
	i64	count;

	c = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
  if (read(fd, &c, 0) < 0)
    return (-1);
	count = 0;
	while (read(fd, &c, 1) > 0)
		count++;
	close(fd);
	return (count);
}

i8	*get_file_content(i8 *file)
{
	i8 *buffer;
	i64 size;
	i32 fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	size = get_file_bytes(file);
  if (size == -1)
    return (NULL);
	buffer = (i8 *)calloc(sizeof(i8), size + 1);
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, size) < 0)
	{
		free(buffer);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (buffer);
}