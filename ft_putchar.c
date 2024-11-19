/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 06:05:43 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/19 09:18:34 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, char *flags, int n_flags)
{
	char	*res;
	int		count;
	int		i;
	if (ft_strchr(flags, '-') == 0)
		return (0);
	res = (char *) malloc(n_flags);
	if (!res)
		return (0);
	i = 0;
	res[i++] = c;
	while (i < n_flags)
	{
		res[i] = ' ';
		i++
	}
	count = write(1, res, n_flags);
	return (free(res), count);
}
