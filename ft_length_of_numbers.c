/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_of_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:40 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/01 18:26:15 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_int_len(unsigned int nb)
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

int	ft_unsigned_ll_len(unsigned long long nb)
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
