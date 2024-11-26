/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:09:38 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/26 16:10:55 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_alloc(int len)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *) malloc(len);
	if (!res)
		return (NULL);
	while (i < len)
		res[i++] = ' ';
	return (res);
}
