/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:55:46 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/28 08:57:42 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_sign(char *res, int nb, t_flags flags, int i)
{
	if (nb < 0)
		res[i] = '-';
	else
	{
		if (flags.sign_flag)
			res[i] = '+';
		else if (flags.space_flag)
			res[i] = ' ';
		}
}
