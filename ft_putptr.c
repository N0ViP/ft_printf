/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:44:23 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/27 06:33:38 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_max(unsigned long long a, unsigned long long b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	ft_itoa_evo(char *res, unsigned long long nb,
	int total_len, t_flags flags)
{
	int	percision;
	int	i;

	percision = ft_max(ft_hexlen_ptr(nb), flags.percision);
	if (flags.left_justify)
		i = percision + 1;
	else
		i = total_len - 1;
	while (percision--)
	{
		res[i--] = "0123456789abcdef"[nb % 16];
		nb /= 16;
	}
	res[i--] = 'x';
	res[i] = '0';
}

int	ft_putptr(unsigned long long nb, t_flags flags)
{
	int		total_len;
	int		count;
	char	*res;

	if (nb == 0)
	{
		flags.percision = -1;
		return (ft_putstr("(nil)", flags));
	}
	total_len = ft_max(flags.percision, ft_hexlen(nb));
	total_len = ft_max(total_len, flags.width);
	if (total_len == ft_hexlen_ptr(nb) || total_len == flags.percision)
		total_len += 2;
	res = ft_alloc_fill(total_len, flags);
	ft_itoa_evo(res, nb, total_len, flags);
	count = write(1, res, total_len);
	return (free(res), count);
}
