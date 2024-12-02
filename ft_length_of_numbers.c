/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_of_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:40 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/02 09:49:36 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_hex_len(unsigned int nb)
{
	int	i;

	i = 1;
	while (nb / 16)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

int	ft_unsigned_ll_len(unsigned long long nb)
{
	int	i;

	i = 1;
	while (nb / 16)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

int	ft_numlen(int nb)
{
	int	i;

	i = 1;
	while (nb / 10)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int	ft_unsigned_int_len(unsigned int nb)
{
	int i;

	i = 1;
	while (nb / 10)
	{
		i++;
		nb /= 10;
	}
	return (i);
}
