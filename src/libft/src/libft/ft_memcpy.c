/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:30:55 by eandre            #+#    #+#             */
/*   Updated: 2024/01/08 14:14:17 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char	*dests;
	char	*srcs;
	size_t	i;

	dests = dest;
	srcs = (char *)src;
	i = 0;
	if (srcs == NULL && dests == NULL && size != 0)
		return (NULL);
	if (size != 0)
	{
		while (i < size)
		{
			dests[i] = srcs[i];
			i++;
		}
	}
	return (dests);
}
