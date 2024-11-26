/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:49:36 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/26 22:10:24 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_type(char c, va_list args, t_flags flags)
{
	int	count;

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
		count = write(1, "%", 1);
	return (count);
}

static void	ft_get_flags(t_flags *flags, char **str)
{
	while (ft_strchr("#0- +", **str))
	{
		flags->left_justify |= (**str == '-');
		flags->sign_flag |= (**str == '+');
		flags->space_flag |= (**str == ' ');
		flags->alternate_form |= (**str == '#');
		if (**str == '0')
			flags->padding = '0';
		(*str)++;
	}
	flags->width = ft_atoi(*str);
	*str += ft_numlen(flags->width);
	if (**str == '.')
	{
		flags->percision = ft_atoi(++(*str));
		while (**str == '0')
			(*str)++;
	}
	*str += ft_numlen(flags->percision);
}

int	ft_there_is_percentage(const char **str, va_list args)
{
	t_flags	flags;
	int		count;

	count = 0;
	(*str)++;
	flags.left_justify = 0;
	flags.padding = ' ';
	flags.space_flag = 0;
	flags.sign_flag = 0;
	flags.percision = -1;
	flags.alternate_form = 0;
	flags.width = 0;
	ft_get_flags(&flags, (char **) str);
	if (ft_strchr("csdiuxX%", **str))
		count = ft_select_type(**str, args, flags);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		tmp;
	int		count;

	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (*str)
	{
		tmp = 0;
		if (*str != 37)
			tmp = write(1, str, 1);
		else
			tmp = ft_there_is_percentage(&str, args);
		if (tmp == -1)
			return (-1);
		count += tmp;
		str++;
	}
	va_end(args);
	return (count);
}
