/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putHex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:31:41 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/27 21:08:41 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_itoa_evo(char *res, unsigned int nb, int total_len, t_flags flags)
{
	unsigned int	percision;
	unsigned int	tmp_nb;
	unsigned int	i;

	tmp_nb = nb;
	percision = ft_max(ft_unumlen(nb, 16), flags.percision);
	if (flags.left_justify)
		i = percision - 1 + (2 * (flags.alternate_form));
	else
		i = total_len - 1;
	if (nb == 0)
		res[i] = '0';
	while (percision--)
	{
		res[i--] = "0123456789ABCDEF"[nb % 16];
		nb /= 16;
	}
	if (flags.alternate_form && tmp_nb > 0)
	{
		res[i--] = 'X';
		res[i] = '0';
	}
}

int	ft_puthex_up(unsigned int nb, t_flags flags)
{
	int		total_len;
	char	*res;

	total_len = ft_max(ft_unumlen(nb, 16), flags.percision)
		+ (2 * ((nb > 0) && (flags.alternate_form)));
	total_len = ft_max(total_len, flags.width);
	res = ft_alloc_fill(total_len, flags);
	if (!res)
		return (-1);
	ft_itoa_evo(res, nb, total_len, flags);
	write(1, res, total_len);
	return (free(res), total_len);
}
