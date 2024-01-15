/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:30:55 by eandre            #+#    #+#             */
/*   Updated: 2024/01/08 14:14:17 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	unsigned char	*p1s;
	unsigned char	*p2s;
	size_t			i;

	p1s = (unsigned char *)p1;
	p2s = (unsigned char *)p2;
	i = 0;
	while (i < size)
	{
		if (p1s[i] != p2s[i])
		{
			return (p1s[i] - p2s[i]);
		}
		i++;
	}
	return (0);
}
