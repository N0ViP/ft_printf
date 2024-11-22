/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:15:18 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/22 21:21:41 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct printf_flags
{
	int left_justify;
	int zero_padding;
	int space_flag;
	int sign_flag;
	int percision;
	int alternate_form;
	int l_z_len; //left_justify || zero_padding lenght
} t_flags;

int	ft_select_type(char c, va_list args, t_flags *flags)
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
		count = ft_put(va_args(args, unsigned int), flags);
	else
		count = write(1, "%", 1);
	return (count);
}

int get_flags(t_flags *flags, char *str, int i)
{
	while (ft_strchr("#0- +", str[i]))
	{
		if (str[i] == '-')
			flags->left_justify = 1;
		else if (str[i] == '+')
			flags->sign_flag = 1;
		else if (str[i] = ' ')
			flags->space_flag = 1;
		else if (str[i] == '0')
			flags->zero_flags = 1;
		else
			flags->alternate_form = 1;
		i++;
	}
	flags->l_z_len = ft_atoi(str + i);
	i += ft_num_len(flags->l_z_len);
	flags->percision = -1;
	if (str[i] == '.')
		flags->percision = ft_atoi(str + i);
	i += ft_num_len(flags->per_len);
	return (i);
}

char *ft_check_flags(char *str, t_flags **flags)
{
	int i;

	i = 0;
	*flags = (t_flags) malloc(t_flags);
	if (!(*flags))
		return (NULL);
	i = get_flags(*flags, str, i);
	return (str + i);
}

int ft_printf(const char *str, ...)
{
	va_list	args;
	int i;
	int count;

	i = 0;
	count = 0;
	t_flags *flags = NULL;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != 37)
			count += write(1, &str[i], 1);
		else
		{
			str = ft_check_flags(str + i + 1, &flags);
			if (str == NULL)
				return (-1);
			if (ft_strchr("csdiuxX%", str[i]))
				count += ft_select_type(str[i], args, flags);
			else
				return (-1);
		}
	}
}
