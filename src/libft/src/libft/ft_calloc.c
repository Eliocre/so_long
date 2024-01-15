/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:06:39 by eandre            #+#    #+#             */
/*   Updated: 2024/01/08 14:14:17 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <limits.h>

void	*ft_calloc(size_t nelem, size_t size)
{
	char	*ptr;

	ptr = NULL;
	if (nelem == 0 || size == 0)
		return (malloc(0));
	if (nelem > INT_MAX / size)
		return (0);
	ptr = malloc(nelem * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nelem * size);
	return (ptr);
}
