/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:22:05 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/28 17:40:03 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_puthex(unsigned int nb, char c);
int		ft_putptr(unsigned long long nb);
char	*ft_strchr(char *str, char c);
int		ft_putuint(unsigned int nb);
int		ft_strlen(char *str);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putint(int nb);

#endif
