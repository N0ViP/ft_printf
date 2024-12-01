/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:00:14 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/01 18:35:47 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_evo(unsigned long long nb,
	int total_len, int precision, t_flags flags)
{
	int		i;
	char	*res;

	res = (char *) malloc(total_len);
	if (!res)
		return (NULL);
	if (flags.width > precision + 2)
		i = ft_fill_with_padding(res, total_len, precision, flags);
	else
		i = precision + 2;
	while (precision--)
	{
		res[i--] = "0123456789abcdef"[nb % 16];
		nb /= 16;
	}
	res[i--] = 'x';
	res[i] = '0';
	return (res);
}

int	ft_putptr(unsigned long long nb, t_flags flags)
{
	int		total_len;
	int		precision;
	char	*res;

	if (nb == 0)
	{
		flags.precision = -1;
		return (ft_putstr("(nil)", flags));
	}
	precision = ft_max(ft_unsigned_ll_len(nb), flags.precision);
	total_len = ft_max(precision + 2, flags.width);
	if (flags.precision != -1 || flags.left_justify)
		flags.padding = ' ';
	res = ft_itoa_evo(nb, total_len, precision, flags);
	if (!res)
		return (-1);
	write(1, res, total_len);
	return (free(res), total_len);
}
