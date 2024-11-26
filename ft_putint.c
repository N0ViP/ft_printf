/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:18:27 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/26 09:01:15 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_sign(char *res, int nb, t_flags flags, int i)
{
	if (nb < 0)
		res[i] = '-';
	else
	{
		if (flags.sign_flag)
			res[i] = '+';
		else if (flags.space_flag)
			res[i] = ' ';
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	ft_itoa_evo(char *res, int nb, int total_len, t_flags flags)
{
	int	i;
	int	percision;
	int	nb_tmp;

	i = 0;
	nb_tmp = nb;
	percision = ft_max(flags.percision, ft_numlen(nb));
	if (flags.left_justify)
		i = percision - !(nb < 0 || flags.sign_flag || flags.space_flag);
	else
		i = total_len - 1;
	while (percision--)
	{
		res[i--] = ft_abs(nb_tmp % 10) + 48;
		nb_tmp /= 10;
	}
	ft_check_sign(res, nb, flags, i);
}

int	ft_putint(int nb, t_flags flags)
{
	int		num_len;
	int		total_len;
	int		count;
	char	*res;

	count = 0;
	num_len = ft_numlen(nb);
	total_len = ft_max(num_len, flags.percision);
	total_len = ft_max(total_len, flags.width);
	if (total_len == num_len || total_len == flags.percision)
		total_len += (nb < 0 || flags.space_flag || flags.sign_flag);
	res = ft_alloc_fill(total_len, flags);
	if (!res)
		return (-1);
	ft_itoa_evo(res, nb, total_len, flags);
	count = write(1, res, total_len);
	return (free(res), count);
}
