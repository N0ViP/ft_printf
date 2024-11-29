/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:36:00 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/27 06:40:23 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char *str, int start, int len)
{
	char	*res;
	int		str_len;
	int		i;

	i = 0;
	str_len = ft_strlen(str);
	if (len < start)
		return (NULL);
	if (len > str_len - start)
		len = str_len - start;
	res = (char *) malloc(len + 1);
	if (!res)
		return (NULL);
	while (len--)
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}
