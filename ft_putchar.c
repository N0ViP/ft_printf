/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:11:13 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/26 21:19:24 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_flags flags)
{
	int		count;
	char	*res;

	count = 0;
	if (flags.width <= 1)
		return (write(1, &c, 1));
	else
	{
		res = ft_alloc(flags.width);
		if (!res)
			return (-1);
		if (flags.left_justify)
			res[0] = 'c';
		else
			res[flags.width - 1] = 'c';
		count = write(1, res, flags.width);
		return (free(res), count);
	}
}
