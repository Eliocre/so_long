/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:38:25 by eandre            #+#    #+#             */
/*   Updated: 2024/01/08 14:16:49 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

static int	format_detector(const char format, va_list varin)
{
	int	len;

	len = 0;
	if (format == 'd' || format == 'i' || format == 'c')
		len = ft_checkint(format, va_arg(varin, int));
	else if (format == 'p')
		len = ft_checkptr(va_arg(varin, long unsigned int));
	else if (format == 'u')
		len = ft_checknumber(format, va_arg(varin, unsigned int));
	else if (format == 'x' || format == 'X')
		len = ft_checknumber(format, va_arg(varin, unsigned int));
	else if (format == 's')
		len = ft_checkstr(va_arg(varin, char *));
	else if (format == '%')
		len = ft_putchar('%');
	else
	{
		len += ft_putchar('%');
		len += ft_putchar(format);
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	int		tmp;
	va_list	varin;

	i = 0;
	len = 0;
	va_start(varin, format);
	while (format[i])
	{
		tmp = len;
		if (format[i] == '%' && format[i + 1] != '\0')
			len += format_detector(format[++i], varin);
		else if ((format[i] == '%' && ft_error(format[i + 1])) || tmp > len)
			return (-1);
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			len++;
		}
		i++;
	}
	va_end(varin);
	return (len);
}
