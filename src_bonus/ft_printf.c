#include "ft_printf.h"

static int      ft_select_type(char c, va_list args, t_flags flags)
{
        int     count;

        count = 0;
        if (c == 'c')
                count = ft_putchar(va_arg(args, int), flags);
        else if (c == 's')
                count = ft_putstr(va_arg(args, char *), flags);
        else if (c == 'd' || c == 'i')
                count = ft_putint(va_arg(args, int), flags);
        else if (c == 'u')
                count = ft_putuint(va_arg(args, unsigned int), flags);
        else if (c == 'x')
                count = ft_puthex(va_arg(args, unsigned int), flags);
        else if (c == 'X')
                count = ft_puthex_up(va_arg(args, unsigned int), flags);
        else if (c == 'p')
                count = ft_putptr((unsigned long long) va_arg(args, void *), flags);
        else
        {
                count = 1;
                write(1, "%", 1);
        }
        return (count);
}

int	ft_check_width_percision(char *format, t_flags *flags)
{
	int	i;

	i = 0;
	flags->width = ft_atoi(format + i);
	i += ft_numlen(flags->width);
	if (format[i] == '.')
	{
		flags->percision = ft_atoi(format + i);
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	}
	if (flags->width == -1 || flags->percision == -1)
			return (-1);
	return (i);
}

int	ft_check_flags(char *format, t_flags *flags)
{
	int	i;

	i = 0;
	while (ft_strchr("#+ -0", format[i]))
	{
		flags->left_justify |= (format[i] == '-');
		flags->sign_flag |= (format[i] == '+');
		flags->space_flag |= (format[i] == ' ');
		flags->alternate_form |= (format[i] == '#');
		if (format[i] == '0')
			flags->padding = '0';
		i++;
	}
	return (i);
}

//p_w_len = percision and width length

int	ft_print_flags(int count, t_flags flags)
{
	write(1, "%", 1);
	count++;
	if (flags.alternate_form)
	{
		write(1, "#", 1);
		count++;
	}
	if (flags.sign_flag || flags.space_flag)
	{
		if (flags.sign_flag)
			write(1, "+", 1);
		else
			write(1, " ", 1);
		count++;
	}
	if (flags.left_justify || flags.padding == '0')
	{
		if (flags.left_justify)
			write(1, "-", 1);
		else
			write(1, "0", 1);
		count++;
	}
	return (count);
}

int	ft_print_width_percision(int count, t_flags flags)
{
	int		width_len;
	int		percision_len;
	t_flags	initial;

	width_len = 0;
	percision_len = 0;
	initial = (t_flags) {0, ' ', 0, 0, -1, 0, 0};
	if (flags.width)
		width_len = ft_putint(flags.width, initial);
	if (flags.percision != -1)
		percision_len = ft_putint(flags.percision, initial);
	if (width_len == -1 || percision_len == -1)
			return (-1);
	count += width_len + percision_len;
	return (count);
}

int	ft_get_flags(char **format, va_list args)
{
	t_flags	flags;
	int		flags_len;
	int		w_p_len;
	int		count;

	count = 0;
	flags = (t_flags) {0, ' ', 0, 0, -1, 0, 0};
	flags_len = ft_check_flags(*format, &flags);
	w_p_len = ft_check_width_percision(*format, &flags);
	if (w_p_len == -1)
			return (-1);
	*format += flags_len + w_p_len + 1;
	if (ft_strchr("csiduxXp%", **format))
		count = ft_select_type(**format, args, flags);
	else
	{
		if (**format == '\0')
				return (-1);
		count = ft_print_flags(count, flags);
		count = ft_print_width_percision(count, flags);
	}
	return (count);
}

int	ft_print_format(char **format, va_list args)
{
	int	count;

	count = 0;
	if (**format != 37)
	{
		write(1, (*format)++, 1);
		return (1);
	}
	else
	{
		(*format)++;
		count = ft_get_flags(format, args);
		return (count);
	}
}

int	ft_pritnf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		tmp;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		tmp = 0;
		tmp = ft_print_format((char **) &format, args);
		if (tmp < 0)
				return (-1);
		count += tmp;
		format++;
	}
	va_end(args);
	return (count);
}
