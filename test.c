#include<stdio.h>

int	ft_check_37(char *str, int bytes)
{
	int	i;
	
	i = 0;
	while (i < bytes && str[i])
	{
		if (str[i] == 37)
			return (1);
		i++;
	}
		return (0);
}

int	ft_strchr(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str[i]);
		i++;
	}
	return (-1);
}

int	ft_select_type(va_list args, char c, char *flags, int n_flags)
{
	int	count;

	if (c == 'c')
		count = ft_putchar(va_arg(args, int), flags, n_flags);
	else if (c == 's')
		count = ft_putstr(va_arg(args, char*), flags, n_flags);
	else if (c == 'p')
		count = ft_putptr((unsigned int)va_arg(args, void*), flags, n_flags);
	else if (c == 'd' || c == 'i')
		count = ft_putint(va_arg(args, int), flags, n_flags);
	else if (c == 'u')
		count = ft_putuint(va_arg(args, unsigned int), flags, n_flags);
	else if (c == 'x')
		count = ft_puthex(va_arg(args, int), flags, n_flags);
	else if (c == 'X')
		count = ft_putHex(va_arg(args, (unsigned int)), flags, n_flags);
	else if (c == '%')
		count = write(1, "%", 1);
	return (count);
}

int	ft_printf_1(char *str, va_list args, int len, int bytes)
{
	int		t_len;
	int		check;
	int		count;
	char	flags[6];
	int		n_flags;
	int		i;
	int		slak;

	t_len = 0;
	count = 0;
	i = 0;
	n_flags = 0;
	while (1)
	{
		if (t_len + bytes > len)
			bytes = len - t_len;
		check = ft_check_37(str, bytes);
		if (check == 1)
		{
			while (*str++ == 37) ;
			str++;
			while ((slak = ft_strchr("-0# +.", str++)) != -1)
				flags[i++] = slak;
			flags[i] = '\0';
			n_flags = ft_atoi(s + i);
			if (ft_strchr("cspdiuxX%", *str))
				count += ft_select_type(args, *str, flags, n_flags);
			str++;
		}
		else
			count += write(1, str, bytes);
		t_len += bytes;
		str += bytes;
		if (str[bytes])
			break ;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		flags;
	int		count;
	int		bytes;
	int		len;

	flags = 0;
	count = 0;
	bytes = 8;
	len = ft_strlen(str);
	va_start(argc, str);
	count = ft_printf_1(str, args, len, flags, bytes);
}
