#include "helper.h"

ui64	tester_strlen(i8 const *str)
{
	ui64	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	tester_putchar(i32 c)
{
	write(1, &c, 1);
}

void	tester_putstr(i8 const *str)
{
	ui64	size;

	if (!str)
		return ;
	size = tester_strlen(str);
	write(1, str, size);
}

void	tester_puts_no_printable(i8 const *str)
{
	ui64	i;

	i = 0;
	while (str[i])
	{
		tester_putc_no_printable(str[i]);
		i++;
	}
}

void	tester_putc_no_printable(i32 c)
{
	i8	*hex;

	hex = "0123456789abcdef";
	if (c < 32)
	{
		tester_putstr("\\");
		if (c >= 16)
		{
			tester_putchar(hex[c / 16]);
			tester_putchar(hex[c % 16]);
		}
		else
		{
			if (c == 10)
				tester_putchar('n');
			else
				tester_putchar(hex[c % 16]);
		}
	}
  else
    tester_putchar(c);
}

i32	tester_strcmp(i8 const *s1, i8 const *s2)
{
	i32	len;
	i32	s1_len;
	i32	s2_len;

	if (!s1 && !s2)
		return (0);
	s1_len = (i32)tester_strlen(s1);
	s2_len = (i32)tester_strlen(s2);
	if (s1_len != s2_len)
		return (s1_len - s2_len);
	len = 0;
	while (s1[len] && s2[len] && s1[len] == s2[len])
		len++;
	if (s1[len] != s2[len])
		return (s1[len] - s2[len]);
	return (0);
}

i32	tester_memcmp(void *s1, void *s2, i64 len)
{
	i32	i;
	ui8	*s1_clone;
	ui8	*s2_clone;

	if (len == 0)
		return (0);
	s1_clone = (ui8 *)s1;
	s2_clone = (ui8 *)s2;
	i = 0;
	while (i < len && s1_clone[i] == s2_clone[i])
		i++;
	if (s1_clone[i] != s2_clone[i])
		return (s1_clone[i] - s2_clone[i]);
	return (0);
}
