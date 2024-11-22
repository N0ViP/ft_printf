/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 03:16:29 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/22 21:41:08 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_sign(int nb, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->sign_flag)
	{
		if (nb < 0)
			return (write(1, "-", 1));
		else
			return (write(1, "+", 1));
	}
	else
	{
		if (flags->space_flag)
		{
			if (nb < 0)
				return (write(1, "-", 1));
			else
				return (write(1, " ", 1));
		}
	}
}

int	ft_putint(int nb, t_flags *flags)
{
	int	count;

	count = 0;
	count += ft_check_sign(nb, flags);
}
