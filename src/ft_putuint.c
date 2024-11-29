/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:59:37 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/28 23:53:51 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unumlen(unsigned int nb)
{
	int	i;

	i = 1;
	while (nb / 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_putuint(unsigned int nb)
{
	int		unum_len;
	int		i;
	char	*res;

	unum_len = ft_unumlen(nb);
	res = (char *) malloc(unum_len);
	if (!res)
		return (-2);
	i = unum_len;
	while (i--)
	{
		res[i] = (nb % 10) + 48;
		nb /= 10;
	}
	write(1, res, unum_len);
	return (free(res), unum_len);
}
