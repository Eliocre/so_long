/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:30:55 by eandre            #+#    #+#             */
/*   Updated: 2024/01/08 14:14:17 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *string, int chrtofind, size_t size)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *)string;
	while (i < size)
	{
		if (str[i] == (char)chrtofind)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
