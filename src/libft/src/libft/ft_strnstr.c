/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:07:58 by eandre            #+#    #+#             */
/*   Updated: 2024/01/08 14:14:17 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *string, const char *tofind, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		m;

	m = ft_strlen(tofind);
	if (tofind[0] == '\0' || string == tofind)
		return ((char *)string);
	i = 0;
	while (string[i] && len > i)
	{
		j = 0;
		while (string[i + j] && tofind[j] && string[i + j] == tofind[j]
			&& (i + j) < len)
			j++;
		if (j == m)
			return ((char *)&string[i]);
		i++;
	}
	return (NULL);
}
