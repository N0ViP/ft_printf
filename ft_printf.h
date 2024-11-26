/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:21:15 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/26 16:24:43 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct printf_flags
{
	int		left_justify;
	char	padding;
	int		space_flag;
	int		sign_flag;
	int		percision;
	int		alternate_form;
	int		width;
}	t_flags;

int		ft_printf(const char *str, ...);
char	*ft_alloc_fill(int total_len, t_flags flags);
char	*ft_alloc(int len);
int		ft_puthex(unsigned int nb, t_flags flags);
int		ft_puthex_up(unsigned int nb, t_flags flags);
int		ft_max(int a, int b);
int		ft_numlen(int nb);
int		ft_hexlen(int nb);
int		ft_putchar(char c, t_flags flags);
int		ft_putuint(unsigned int nb, t_flags flags);
int		ft_putptr(unsigned long long nb);
int		ft_strlen(char *str);
char	*ft_substr(char *str, int start, int len);

#endif