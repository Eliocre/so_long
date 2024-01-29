/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:39:23 by eandre            #+#    #+#             */
/*   Updated: 2024/01/29 16:37:56 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strs;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	strs = malloc(sizeof(char) * (len + 1));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		strs[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		strs[i] = s2[j];
		j++;
		i++;
	}
	strs[i] = '\0';
	return (strs);
}
