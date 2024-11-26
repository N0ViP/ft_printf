/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putHex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:44:18 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/26 10:48:31 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoa_evo(char *res, int nb, int total_len, t_flags flags)
{
	int	percision;
	int	i;

	percision = ft_max(ft_hexlen(nb), flags.percision);
	if (flags.left_justify)
		i = percision - 1 + (2 * (flags.alternate_form));
	else
		i = total_len - 1;
	while (percision--)
	{
		res[i--] = "0123456789ABCDEF"[nb % 16];
		nb /= 16;
	}
	if (flags.alternate_form)
	{
		res[i--] = 'X';
		res[i] = '0';
	}
}

int	ft_putHex(unsigned int nb, t_flags flags)
{
	int		total_len;
	int		count;
	char	*res;

	total_len = ft_max(ft_hexlen(nb), flags.percision);
	total_len = ft_max(total_len, flags.width);
	if (total_len == ft_fexlen(nb) || total_len == flags.percision)
		total_len += (2 * (flags.alternate_form));
	res = ft_alloc_fill(total_len, flags);
	if (!res)
		return (-1);
	ft_itoa_evo(res, nb, total_len, flags);
	count = write(1, res, total_len);
	return (free(res), count);
}