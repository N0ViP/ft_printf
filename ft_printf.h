/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:41:19 by yjaafar           #+#    #+#             */
/*   Updated: 2024/12/02 09:51:10 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags
{
	int		alternate_form;
	int		sign_flag;
	int		space_flag;
	int		left_justify;
	int		precision;
	int		width;
	char	base;
	char	padding;
}	t_flags;

int		ft_abs(int nb);
int		ft_numlen(int nb);
int		ft_atoi(char **str);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, char c);
int		ft_putint(int nb, t_flags flags);
int		ft_putchar(char c, t_flags flags);
int		ft_printf(const char *format, ...);
int		ft_putstr(char *str, t_flags flags);
int		ft_unsigned_hex_len(unsigned int nb);
int		ft_unsigned_int_len(unsigned int nb);
void	*ft_memset(void *res, int len, char c);
int		ft_unsigned_ll_len(unsigned long long nb);
int		ft_puthex(unsigned int nb, t_flags flags);
int		ft_putuint(unsigned int nb, t_flags flags);
int		ft_putptr(unsigned long long nb, t_flags flags);
int		ft_fill_with_padding(char *res, int total_len,
			int precision, t_flags flags);

#endif
