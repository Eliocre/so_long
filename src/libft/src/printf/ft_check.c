/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:26:37 by eandre            #+#    #+#             */
/*   Updated: 2023/11/27 18:26:37 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_checkstr(char *str)
{
	if (str == NULL)
		return (ft_putstr("(null)"));
	return (ft_putstr(str));
}

int	ft_checkptr(long unsigned int ptr)
{
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	return (ft_putptr_base(ptr, "0123456789abcdef", 0));
}

int	ft_checkint(char c, int n)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr_base(n, "0123456789"));
	else
		return (ft_putchar(n));
}

int	ft_checknumber(char c, unsigned int n)
{
	if (c == 'x')
		return (ft_putnbr_base(n, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(n, "0123456789ABCDEF"));
	else
		return (ft_putnbr_base(n, "0123456789"));
}

int	ft_error(char format)
{
	if (format == 'q' || format == 't' || format == 'h'
		|| format == 'j' || format == 'l' || format == 'z' || format == '\0')
		return (1);
	return (0);
}
