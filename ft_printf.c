/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:34:52 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/19 19:00:36 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strchr(const char *str, char c)
{
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == c)
			return (*str);
		str++;
	}
	if (*str == c)
		return (*str);
	return (-1);
}

int	ft_atoi(char *str, char)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while(str[i] >= 48 && str[i] <= 57)
	{
		res += (res * 10) + (str[i] - 48);
		i++;
	}
}

void	ft_select_type(va_list args, char c, char *flags, int n_flags, int nn_flags)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), flags, count);
	if (c == 's')
		ft_putstr(va_arg(args, char*), *flags, );
	if (c == 'p')
		ft_putptr((unsigned int)va_arg(args, void*), flags, count);
	if (c == 'd' || c == 'i')
		ft_putint(va_arg(args, int), flags, count);
	if (c == 'u')
		ft_putuint(va_arg(args, unsigned int), flags, count);
	if (c == 'x')
		ft_puthex(va_arg(args, int), flags, count);
	if (c == 'X')
		ft_putHex(va_arg(args, (unsigned int)), flags, count);
	if (c == '%')
		*count += write(1, "%", 1);
}

int ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		flags[7];
	int		n_flags;
	int		count;
	int		s;
	int		nn_flags;
	int j = 0;

	i = 0;
	n_flags = 0;
	if_there_is_flags = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == 37)
		{
			i++;
			while ((s = ft_strchr("-0# +.", str[i++])) != -1)
			    flags[j++] = s;
			nn_flags = ft_atoi(s + i);
			while (str[i] && str[i] >= 48 && str[i] <= 57)
				i++;
			while ((s = ft_strchr("-0# +.", str[i++])) != -1)
				flags[j++] = s;
			n_flags = ft_atoi(s + i);
			while (str[i] && str[i] >= 48 && str[i] <= 57)
			    i++;
			if (ft_strchr("cspdiuxX%", str[i]))
				ft_select_type(args, str[i], flags, &count);
			i++;
		}
		count += write(1, str[i], 1);
		i++;
	}
}
