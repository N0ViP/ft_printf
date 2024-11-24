/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:32:47 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/24 10:18:12 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct printf_flags
{
    int     left_justify;
    char    padding;
    int     space_flag;
    int     sign_flag;
    int     percision;
    int     alternate_form;
    int     width;
} t_flags;

int ft_numlen(int n)
{
	int i = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_alloc(int total_len, t_flags flags)
{
	char	*res;
	int		i;
	char	padding;

	i = 0;
	if (flags.percision)
		padding = ' ';
	res = (char *) malloc(total_len);
	if (!res)
		return (NULL);
	while (i < total_len)
		res[i++] = padding;
	return (res);
}

void	ft_check_sign(char *res, int nb, t_flags flags, int *i)
{
	if (nb < 0)
		res[(*i)++] = '-';
	else
	{
		if (flags.sign_flag)
			res[*i] = '+';
		else if (flags.space_flag)
			res[(*i)++] = ' ';
	}
}

void	ft_itoa_custom(char *res, int nb, int total_len, t_flags flags)
{
	int	i;
	int	percision;
	int	sign;

	i = 0;
	sign = 0;
	percision = flags.percision;
	if (percision < ft_numlen(nb))
		percision = ft_numlen(nb);
	if (flags.left_justify)
	{
		i = 
	}
	else
	{
		
	}
	while (i > percision)
	{
	    res[i--] =0 (nb % 10) + 48;
	    nb /= 10;
	}
	ft_check_sign(res, nb, flags, &i);
}

int	ft_putint(int nb, t_flags flags)
{
	int		total_len;
	int		count;
	char	*res;

	count = 0;
	total_len = ft_numlen(nb);
	if (flags.width > total_len)
		total_len = flags.width;
	if (flags.percision > total_len)
		total_len = flags.percision;
	if (total_len == ft_numlen(nb))
		total_len += (nb < 0 || flags.sign_flag || flags.space_flag);
	res = ft_alloc(total_len, flags);
	ft_itoa_custom(res, nb, total_len, flags);
	count = write(1, res, total_len);
	return (free(res), count);
}

int main()
{
	t_flags flags = {0, ' ', 0, 1, 0, 0, 15};
	ft_putint(1337, flags);
	printf("\n%+15i", 1337);
}


