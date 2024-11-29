/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:13:08 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/27 15:54:41 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fill(char *res, char *str, int str_len, t_flags flags)
{
	int	i;

	i = 0;
	if (flags.left_justify)
		while (*str)
			res[i++] = *str++;
	else
	{
		i = flags.width - str_len;
		while (i < flags.width && *str)
			res[i++] = *str++;
	}
}

static int	ft_printstr(char *res, char *str, int str_len, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width > str_len)
	{
		res = ft_alloc(flags.width);
		if (!res)
			return (-1);
		ft_fill(res, str, str_len, flags);
		count = flags.width;
		write(1, res, flags.width);
		free(res);
	}
	else
	{
		count = str_len;
		write(1, str, str_len);
	}
	return (count);
}

int	ft_putstr(char *str, t_flags flags)
{
	char	*res;
	int		str_len;
	int		count;

	res = NULL;
	if (!str)
	{
		if (flags.percision >= 6 || flags.percision == -1)
			str = "(null)";
		else
			str = "";
	}
	str_len = ft_strlen(str);
	count = 0;
	if (flags.percision != -1)
	{
		str = ft_substr(str, 0, flags.percision);
		str_len = flags.percision;
	}
	else
		str = ft_substr(str, 0, str_len);
	if (!str)
		return (-1);
	count = ft_printstr(res, str, str_len, flags);
	return (free(str), count);
}
