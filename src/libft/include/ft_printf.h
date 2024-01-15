/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:14:56 by eandre            #+#    #+#             */
/*   Updated: 2024/01/08 15:47:09 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../include/libft.h"

int	ft_printf(const char *format, ...);
int	ft_putptr_base(long unsigned int n, char *base, int bool_);
int	ft_putnbr_base(long n, char *base);
int	ft_checkstr(char *str);
int	ft_checkptr(long unsigned int ptr);
int	ft_checkint(char c, int n);
int	ft_checknumber(char c, unsigned int n);
int	ft_error(char format);
int	ft_putstr(char *s);
int	ft_putchar(char c);

#endif
