/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:11:13 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/23 14:27:44 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_alloc_fill(int width)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *) malloc(width + 1);
	while (i < width)
		res[i++] = ' ';
	res[i] = '\0';
	return (res);
}

void	ft_fill_res(char *res, char c, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->left_justify)
	{
		res[i++] = 'c';
		while (i < flags->width)
			res[i++] = ' ';
	}
	else
	{
		while (i < (flags->width - 1))
			res[i++] = ' ';
		res[i] = 'c';
	}
}

int	ft_putchar(char c, t_flags *flags)
{
	int		count;
	char	*res;

	count = 0;
	if (flags->width <= 1)
		return (write(1, &c, 1));
	else
	{
		res = ft_alloc_fill(flags->width);
		ft_fill_res(res, c, flags);
		count = write(1, res, flags->width);
		return (free(res), coun);
	}
}
