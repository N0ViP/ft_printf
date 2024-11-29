/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:51:32 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/29 09:11:58 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_select_type(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count = ft_putint(va_arg(args, int));
	else if (c == 'u')
		count = ft_putuint(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		count = ft_putptr((unsigned long long) va_arg(args, void *));
	else
	{
		count = 1;
		write(1, "%", 1);
	}
	return (count);
}

int	ft_check_format(char **str, va_list args)
{
	int	count;

	count = 0;
	if (ft_strchr("csiduxXp%", *(*str + 1)))
	{
		count = ft_select_type(args, *(*str + 1));
		(*str)++;
	}
	else
	{
		count = 1;
		write(1, *str, 1);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		tmp;

	count = 0;
	tmp = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			tmp = 1;
			write(1, str, 1);
		}
		else
			tmp = ft_check_format((char **) &str, args);
		if (tmp == -2)
			return (-1);
		count += tmp;
		str++;
	}
	va_end(args);
	return (count);
}
