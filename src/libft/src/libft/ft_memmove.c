/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:30:55 by eandre            #+#    #+#             */
/*   Updated: 2024/01/08 14:14:17 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*dests;
	char	*srcs;

	dests = (char *)dest;
	srcs = (char *)src;
	if (srcs == NULL && dests == NULL && size != 0)
		return (NULL);
	if (size != 0)
	{
		if (dests > srcs)
			while (size-- > 0)
				dests[size] = srcs[size];
		else
			ft_memcpy(dests, srcs, size);
	}
	return (dests);
}
