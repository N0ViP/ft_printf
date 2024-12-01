/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:18:27 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/28 09:20:06 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_sign(char *res, int nb, t_flags flags, int i)
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

static void	ft_itoa_evo(char *res, int nb, int total_len, t_flags flags)
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
	if (nb == 0 && flags.percision == -1)
		res[i] = '0';
	while (percision--)
	{
		res[i--] = ft_abs(nb_tmp % 10) + 48;
		nb_tmp /= 10;
	}
	if (nb != 0)
		ft_check_sign(res, nb, flags, i);
}

int	ft_putint(int nb, t_flags flags)
{
	int		num_len;
	int		total_len;
	char	*res;

	num_len = ft_numlen(nb);
	total_len = ft_max(num_len, flags.percision)
		+ (nb < 0 || flags.space_flag || flags.sign_flag);
	total_len = ft_max(total_len, flags.width);
	res = ft_alloc_fill(total_len, flags);
	if (!res)
		return (-1);
	ft_itoa_evo(res, nb, total_len, flags);
	write(1, res, total_len);
	return (free(res), total_len);
}
