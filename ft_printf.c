/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:49:36 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/26 15:55:49 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_type(char c, va_list args, t_flags flags)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_args(args, int), flags);
	else if (c == 's')
		count = ft_putstr(va_args(args, char *), flags);
	else if (c == 'd' || c == 'i')
		count = ft_putint(va_args(args, int), flags);
	else if (c == 'u')
		count = ft_putuint(va_args(args, unsigned int), flags);
	else if (c == 'x')
		count = ft_puthex(va_args(args, unsigned int), flags);
	else if (c == 'X')
		count = ft_putHex(va_args(args, unsigned int), flags);
	else if (c == 'p')
		count = ft_putptr(va_args(args, void *), flags);
	else
		count = write(1, "%", 1);
	return (count);
}

static int	ft_get_flags(t_flags *flags, char *str, int i)
{
	while (ft_strchr("#0- +", str[i]))
	{
		flags->left_justify |= (str[i] == '-');
		flags->sign_flag |= (str[i] == '+');
		flags->space_flag |= (str[i] == ' ');
		flags->alternate_form |= (str[i] == '#');
		if (str[i] == '0')
			flags->padding = '0';
		i++;
	}
	flags->l_z_len = ft_atoi(str + i);
	i += ft_num_len(flags->l_z_len);
	if (str[i] == '.')
	{
		flags->percision = ft_atoi(str + (++i));
		while (str[i] == '0')
			i++;
	}
	i += ft_num_len(flags->per_len);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != 37)
			count += write(1, &str[i], 1);
		else
		{
			flags = {0, ' ', 0, 0, -1, 0, 0};
			i = ft_get_flags(&flags, str, i);
			if (ft_strchr("csdiuxX%", str[i]))
				count += ft_select_type(str[i], args, flags);
		}
		i++;
	}
	va_end(args);
	return (count);
}
