/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:13:08 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/23 14:02:13 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_alloc(int len)
{
	char	*res;
	int		i;

	res = (char *) malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
		res[i++] = ' ';
	res[i] = '\0';
	return (res);
}

void	ft_fill(char *res, char *str, int str_len, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->left_justify)
	{
		while (*str)
			res[i++] = *str++;
		while (i < flags->width)
			res[i++] = ' ';
	}
	else
	{
		while (i < (flags->width - str_len))
			res[i++] = ' ';
		while (i < flags->width)
			res[i++] = *str++;
	}
}

int	ft_putstr(char *str, t_flags *flags)
{
	char	*res;
	int		str_len;
	int		count;

	str_len = ft_strlen(str);
	count = 0;
	if (flags->percision != -1)
		str = ft_substr(str, 0, flags->percision);
	else
		str = ft_substr(str, 0, str_len);
	if (!str)
		return (-1);
	if (flags->width > str_len)
	{
		res = ft_alloc(flags->width);
		if (!res)
			return (-1);
		ft_fill(res, str, str_len, flags);
		count = write(1, res, flags->width);
		free(res);
	}
	else
		count = write(1, str, str_len);
	free(str);
	return (count);
}
