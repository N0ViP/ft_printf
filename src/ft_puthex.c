/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:32:39 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/28 17:44:55 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb / 16)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

static char	*ft_select_base(char c)
{
	if (c == 'x')
		return ("0123456789abcdef");
	return ("0123456789ABCDEF");
}

int	ft_puthex(unsigned int nb, char c)
{
	int		hex_len;
	int		i;
	char	*base;
	char	*res;

	hex_len = ft_hexlen(nb);
	base = ft_select_base(c);
	i = hex_len - 1;
	res = (char *) malloc(hex_len);
	if (!res)
		return (-2);
	while (i)
	{
		res[i--] = base[nb % 16];
		nb /= 16;
	}
	write(1, res, hex_len);
	return (free(res), hex_len);
}
