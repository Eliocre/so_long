/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:56:24 by eandre            #+#    #+#             */
/*   Updated: 2024/01/08 14:16:49 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include <unistd.h>

int	ft_putnbr_base(long n, char *base)
{
	long	len;
	int		value;

	value = 0;
	len = ft_strlen(base);
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		value++;
		n *= -1;
	}
	if (n >= len)
	{
		value += ft_putnbr_base(n / len, base);
		if (value == -1)
			return (-1);
		value += ft_putnbr_base(n % len, base);
		if (value == -1)
			return (-1);
	}
	if (n <= (len - 1))
		value += write(1, &base[n], 1);
	return (value);
}

int	ft_putptr_base(long unsigned int n, char *base, int bool_)
{
	long unsigned int	len;
	int					value;

	value = 0;
	len = ft_strlen(base);
	if (bool_ == 0)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		value += 2;
		bool_ = 1;
	}
	if (n >= len)
	{
		value += ft_putptr_base(n / len, base, bool_);
		if (value == -1)
			return (-1);
		value += ft_putptr_base(n % len, base, bool_);
		if (value == -1)
			return (-1);
	}
	else
		value += write(1, &base[n], 1);
	return (value);
}
