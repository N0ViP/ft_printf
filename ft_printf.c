/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:13:59 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/01 18:43:08 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_percentage(char *format)
{
	int	i = 0;

	while (format[i])
	{
		if (format[i] == '%')
			return (i);
		i++;
	}
	return (i);
}

int	ft_get_flags(char *format, t_flags *flags)
{
	int	i;

	i = 0;
	while (ft_strchr("#+ -0", format[i]))
	{
		if (format[i] == '#')
			flags->alternate_form = 1;
		else if (format[i] == '+')
			flags->sign_flag = 1;
		else if (format[i] == ' ')
			flags->space_flag = 1;
		else if (format[i] == '-')
			flags->left_justify = 1;
		else if (format[i] == '0')
			flags->padding = '0';
		i++;
	}
	return (i);
}

int	ft_get_width_precision(char *format, t_flags *flags)
{
	int	i;

	i = 0;
	flags->width = ft_atoi(format);
	if (flags->width == -2)
		return (-1);
	if (flags->width)
		i += ft_numlen(flags->width);
	if (*format == '.')
	{
		i++;
		flags->precision = ft_atoi(format);
		if (flags->precision == -2)
			return (-1);
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	}
	return (i);
}

int	ft_select_type(char c, va_list args, t_flags flags)
{
	int	count;

	if (c == 'c')
		count = ft_putchar(va_arg(args, int), flags);
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *), flags);
	else if (c == 'i' || c == 'd')
		count = ft_putint(va_arg(args, int), flags);
	else if (c == 'x' || c == 'X')
	{
		flags.base = c;
		count = ft_puthex(va_arg(args, unsigned int), flags);
	}
	else if (c == 'u')
		count = ft_putuint(va_arg(args, unsigned int), flags);
	else if (c == 'p')
		count = ft_putptr((unsigned long long) va_arg(args, void *), flags);
	else
	{
		count = 1;
		write(1, "%", 1);
	}
	return (count);
}

int	ft_print_flags(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.alternate_form)
	{
		count++;
		write(1, "#", 1);
	}
	if (flags.sign_flag || flags.space_flag)
	{
		count++;
		if (flags.sign_flag)
			write(1, "+", 1);
		else
			write (1, " ", 1);
	}
	if (flags.left_justify || flags.padding == '0')
	{
		count++;
		if (flags.left_justify)
			write(1, "-", 1);
		else
			write(1, "0", 1);
	}
	return (count);
}

int	ft_print_width_precision(t_flags flags)
{
	int		width_len;
	int		precision_len;
	t_flags	initial;

	width_len = 0;
	precision_len = 0;
	initial = (t_flags){0, 0, 0, 0, -1, 0, 'b', ' '};
	if (flags.width != 0)
		width_len = ft_putint(flags.width, initial);
	if (width_len == -1)
		return (-1);
	if (flags.precision != -1)
	{
		write(1, ".", 1);
		precision_len = ft_putint(flags.precision, initial);
		if (precision_len == -1)
			return (-1);
		precision_len += 1;
	}
	return (width_len + precision_len);
}

int	ft_theres_no_type(t_flags flags)
{
	int	flags_len;
	int	width_precision_len;

	write(1, "%", 1);
	flags_len = ft_print_flags(flags);
	width_precision_len = ft_print_width_precision(flags);
	if (width_precision_len == -1)
		return (-1);
	return (flags_len + width_precision_len);
}

int	ft_get_flags_and_select_type(char **format, va_list args)
{
	int		flags_len;
	int		width_precision_len;
	int		count;
	t_flags	flags;

	flags = (t_flags){0, 0, 0, 0, -1, 0, 'b', ' '};
	flags_len = ft_get_flags(*format, &flags);
	width_precision_len = ft_get_width_precision(*(format + flags_len), &flags);
	if (width_precision_len == -1)
		return (-1);
	*format += flags_len + width_precision_len;
	if (**format == '\0')
		return (-1);
	if (ft_strchr("csiduxXp%", **format))
		count = ft_select_type(**format, args, flags);
	else
		count = ft_theres_no_type(flags);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		tmp;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		i = ft_check_percentage((char *) format);
		write(1, format, i);
		count += i;
		if (format[i] == '\0')
			return (count);
		if (format[i] == '%')
		{
			format += i + 1;
			tmp = ft_get_flags_and_select_type((char **) &format, args);
			if (tmp == -1)
				return (-1);
		}
		count += tmp;
		format++;
	}
	return (va_end(args), i);
}
