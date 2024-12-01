/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:50:47 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/28 17:50:08 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str >= 48 && *str <= 57)
	{
		res = (res * 10);
		if (res < 0)
			return (-1);
		res += *str - 48;
		str++;
	}
	return (res);
}
