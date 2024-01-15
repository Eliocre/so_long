/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:58:27 by eandre            #+#    #+#             */
/*   Updated: 2024/01/08 14:14:17 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static size_t	start(char const *s1, char const *set)
{
	int		i;
	int		len;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

static size_t	end(char const *s1, char const *set)
{
	int		i;
	int		len;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[(len - i - 1)]) == NULL)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		start_v;
	size_t		end_v;
	int			k;

	start_v = start(s1, set);
	end_v = end(s1, set);
	if (start_v == ft_strlen(s1))
		return (ft_strdup(""));
	str = malloc((end_v - start_v + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	k = 0;
	while (s1[start_v] && start_v < end_v)
	{
		str[k] = s1[start_v];
		k++;
		start_v++;
	}
	str[k] = '\0';
	return (str);
}
