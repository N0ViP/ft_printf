/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:12:54 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/28 17:46:04 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(unsigned long long nb)
{
	int	i;

	i = 1;
	while (nb / 16)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int	ft_putptr(unsigned long long nb)
{
	int		ptr_len;
	int		i;
	char	*res;

	ptr_len = ft_ptrlen(nb);
	res = (char *) malloc(ptr_len + 2);
	if (!res)
		return (-2);
	i = ptr_len - 1;
	while (i)
	{
		res[i--] = "0123456789abcdef"[nb % 16];
		nb /= 16;
	}
	res[i--] = 'x';
	res[i] = '0';
	write(1, res, ptr_len + 2);
	return (free(res), ptr_len + 2);
}