/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 06:47:55 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/19 09:45:14 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int ft_strchr(const char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (str[i]);
        i++;
    }
    return (-1);
}


int	ft_putstr(char *str, char *flags, int n_flags)
{
	char	*res;
	int		len;
	int		count;
	int		i;

	len = strlen(str);
	if (ft_strchr(flags, '-') == -1)
		return (-1);
	if (len > n_flags)
		count = write(1, str, len);
	else
	{
		i = 0;
		res = (char *) malloc(n_flags);
		if (!res)
			return (-1);
		while (*str && i < n_flags)
			res[i++] = *str++;
		while (i < n_flags)
			res[i++] = ' ';
		count = write(1, res, n_flags);
		free(res);
	}
	return (count);
}

int main()
{
	char *flags = "-SLD";
	char *str = "hello world";
	int n_flags = 20;
	printf("%d\n", ft_putstr(str, flags, n_flags));
}
