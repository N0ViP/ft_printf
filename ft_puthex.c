/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:32:09 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/25 18:55:58 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

static void	ft_itoa_evo(char *res, int nb, int total_len, t_flags flags)
{
	int		percision;
	int		i;

	percision = ft_max(ft_hexlen(nb), flags.percision);
	if (flags.left_justify)
		i = percision - 1 + ((flags.alternate_form) * 2);
	else
		i = percision - 1;
	while (percision)
	{
		res[i--] = "0123456789abcdef"[nb % 16];
		nb /= 16;
	}
	if (flags.alternate_form)
	{
		res[i--] = 'x';
		res[i] = '0';
	}
}

int	ft_puthex(unsigned int nb, t_flags flags)
{
	int		total_len;
	char	*res;

	total_len = ft_max(ft_hexlen(nb), flags.percision);
	total_len = ft_max(total_len, flags.width);
	res = ft_alloc_fill(total_len, flags);
	ft_itoa_evo(res, nb, total_len, flags);
}
