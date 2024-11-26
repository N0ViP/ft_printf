/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:13:08 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/26 10:08:44 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_alloc(int len)
{
	char	*res;
	int		i;

	res = (char *) malloc(len);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
		res[i++] = ' ';
	return (res);
}

void	ft_fill(char *res, char *str, int str_len, t_flags flags)
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

int	ft_printstr(char *res, int str_len, t_flags iflags)
{
	int	count;

	count = 0;
	if (flags.width > str_len)
	{
		res = ft_alloc(flags.width);
		if (!res)
			return (-1);
		ft_fill(res, str, str_len, flags);
		count = write(1, res, flags.width);
		free(res);
	}
	else
		count = write(1, str, str_len);
	return (count);
}

int	ft_putstr(char *str, t_flags flags)
{
	char	*res;
	int		str_len;
	int		count;

	if (!str)
	{
		if (flags.percision >= 6)
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
	count = ft_printstr(res, str_len, flags);
	return (free(str), count);
}
