/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:12:54 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/29 08:45:13 by yjaafar          ###   ########.fr       */
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
	int		ptr_len_tmp;
	char	*res;

	if (nb == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ptr_len = ft_ptrlen(nb);
	ptr_len_tmp = ptr_len;
	res = (char *) malloc(ptr_len + 2);
	if (!res)
		return (-2);
	i = ptr_len + 1;
	while (ptr_len--)
	{
		res[i--] = "0123456789abcdef"[nb % 16];
		nb /= 16;
	}
	res[i--] = 'x';
	res[i] = '0';
	write(1, res, ptr_len_tmp + 2);
	return (free(res), ptr_len_tmp + 2);
}
