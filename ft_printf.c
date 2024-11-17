/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:34:52 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/16 21:52:07 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



char	*ft_strchr(const char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return ((char *) str);
		str++;
	}
	if (*str == c)
		return ((char *) str);
	return (NULL);
}

void	ft_select_type(va_list args, char c, int flags, int *count)
{
	if (c == 'c')
		ft_putchar(ar
}

int ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		flags;
	int		count;

	i = 0;
	if_there_is_flags = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == 37)
		{
			i++;
			while (ft_strchr("-0# +", str[i]))
			{
				flags++;
				i++;
			}
			if (ft_strchr("cspdiuxX%", str[i]))
			{
				ft_select_type(args, str[i], flags, &count);
				i++;
			}
		}
	}
}
