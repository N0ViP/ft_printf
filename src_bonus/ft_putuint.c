/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:49:11 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/27 21:07:29 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_itoa_evo(char *res, unsigned int nb, int total_len, t_flags flags)
{
	int	percision;
	int	i;

	i = 0;
	percision = ft_max(flags.percision, ft_unumlen(nb, 10));
	if (flags.left_justify)
		i = percision - 1;
	else
		i = total_len - 1;
	if (nb == 0)
		res[i] = '0';
	while (percision--)
	{
		res[i--] = (nb % 10) + 48;
		nb /= 10;
	}
}

int	ft_putuint(unsigned int nb, t_flags flags)
{
	int		total_len;
	char	*res;

	total_len = ft_max(flags.percision, ft_unumlen(nb, 10));
	total_len = ft_max(flags.width, total_len);
	res = ft_alloc_fill(total_len, flags);
	ft_itoa_evo(res, nb, total_len, flags);
	write(1, res, total_len);
	return (free(res), total_len);
}
