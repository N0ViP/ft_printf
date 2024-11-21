/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:23:10 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/21 23:41:13 by yjaafar          ###   ########.fr       */
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

int putstring(char *str)
{
	int	i;

	i = ft_strlen(str);
	return (write(1, str, i));
}

void	ft_last_result(char *res, char *tmp, t_flags *flags)
{
	int	tmp_len;
	int	i;

	tmp_len = ft_strlen(tmp);
	i = 0;
	if (!flags->left_justify)
	{
		while (tmp[i])
			res[i++] = *tmp++;
		while (i < flags->l_z_len;)
			res[i++] = ' ';
		res[i] = '\0';
	}
	else
	{
		while (i < flags->l_z_len - tmp)
			res[i++] = ' ';
		while (i < flags->l_z_len)
			res[i++] = *tmp++;
		res[i] = '\0';
	}
}

int	ft_putstr(char *str, t_flags *flags)
{
	int		str_len;
	char	*res;
	char	*tmp;

	str_len = ft_strlen(str);
	if (!flags->l_z_len < str_len)
	{
		return (ft_
	}
	else if (flags->l_z_len > str_len)
	{
		res = (char *) malloc(str_len + 1);
		if (!res)
			return (-1);
		if (flags->percision)
			tmp = ft_substr(str, 0, flags->percision);
		else
			tmp = str;
		ft_last_result(res, tmp, flas);
		return (putstring(res));
	}
}
