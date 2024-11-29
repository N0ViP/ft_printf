/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_and_fill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 02:52:47 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/26 11:17:55 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_alloc_fill(int total_len, t_flags flags)
{
	char	*res;
	char	padding;
	int		i;

	i = 0;
	res = (char *) malloc(total_len);
	if (!res)
		return (NULL);
	if (flags.percision != -1 || flags.left_justify)
		padding = ' ';
	else
		padding = flags.padding;
	while (i < total_len)
		res[i++] = padding;
	return (res);
}
