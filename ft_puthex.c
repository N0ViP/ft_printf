/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:42:43 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/26 21:43:39 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_itoa_evo(char *res, int nb, int total_len, t_flags flags)
{
	int		percision;
	int		i;
	int		tmp_nb;

	tmp_nb = nb;
	percision = ft_max(ft_hexlen(nb), flags.percision);
	if (flags.left_justify)
		i = percision - 1 + ((flags.alternate_form) * 2);
	else
		i = total_len - 1;
	while (percision)
	{
		res[i--] = "0123456789abcdef"[nb % 16];
		nb /= 16;
	}
	if (flags.alternate_form && tmp_nb > 0)
	{
		res[i--] = 'x';
		res[i] = '0';
	}
}

int	ft_puthex(unsigned int nb, t_flags flags)
{
	int		total_len;
	int		count;
	char	*res;

	total_len = ft_max(ft_hexlen(nb), flags.percision);
	total_len = ft_max(total_len, flags.width);
	if (nb > 0 && (total_len == flags.percision || total_len == ft_hexlen(nb)))
		total_len += (2 * (flags.alternate_form));
	res = ft_alloc_fill(total_len, flags);
	ft_itoa_evo(res, nb, total_len, flags);
	count = write(1, res, total_len);
	return (free(res), count);
}
