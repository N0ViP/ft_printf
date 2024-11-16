/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:34:52 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/16 10:28:15 by yjaafar          ###   ########.fr       */
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

int ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		if_there_is_flags;
	char	*flags;
	char	*type;

	i = 0;
	if_there_is_flags = 0;
	flags = "-0# +";
	type = "cspdiuxX%";
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == 37)
		{
			i++;
			while (ft_strchr(flags, str[i]))
			{
				if_there_is_flags++;
				i++;
			}
			if (ft_strchr(type, str[i])_
		}
	}
}
