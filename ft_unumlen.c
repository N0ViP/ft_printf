/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:33:04 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/27 21:07:00 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unumlen(unsigned int nb, int base)
{
	int	i;

	i = 1;
	while (nb / base)
	{
		i++;
		nb /= base;
	}
	return (i);
}
