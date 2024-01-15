/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:41:55 by eandre            #+#    #+#             */
/*   Updated: 2024/01/08 14:14:17 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strrchr(const char *string, int chrtofind)
{
	int		i;
	char	*str;

	str = (char *)string;
	i = 0;
	while (str[i])
		i++;
	while (i >= 0 && str[i] != (char)chrtofind)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return (&str[i]);
}
