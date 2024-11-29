/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:10:34 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/29 08:53:07 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int nb)
{
	int	i;

	i = 1;
	while (nb / 10)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

static int	ft_abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

int	ft_putint(int nb)
{
	int		num_len;
	int		i;
	int		sign;
	char	*res;

	sign = 0;
	num_len = ft_numlen(nb);
	if (nb < 0)
		sign = 1;
	res = (char *) malloc(num_len + sign);
	if (!res)
		return (-2);
	i = num_len + (sign);
	while (i--)
	{
		res[i] = ft_abs(nb % 10) + '0';
		nb /= 10;
	}
	if (sign)
		res[0] = '-';
	write(1, res, num_len + sign);
	return (free(res), (num_len + sign));
}
