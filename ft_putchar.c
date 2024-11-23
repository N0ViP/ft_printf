/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:51:59 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/23 09:06:55 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_char(char *res, char c, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->left_justify)
	{
		res[i++] = c;
		while (i < flags->l_z_len)
			res[i++] = ' ';
	}
	else
	{
		flags->l_z_len--;
		res[flags->l_z_len--] = c;
		while (flags->l_z_len >= 0)
			res[flags->l_z_len--] = ' ';
	}
}

int	ft_putchar(char c, t_flags *flags)
{
	char	*res;
	int		count;

	count = 0;
	if (flags->l_z_len <= 1)
		count = write(1, &c, 1);
	else
	{
		res = (char *) malloc(flags->l_z_len);
		if (!res)
			return (-1);
		ft_write_char(res, c, flags);
		count = write(1, res, flags->l_z_len);
		free(res);
	}
	return (count);
}
