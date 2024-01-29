/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:38:38 by eandre            #+#    #+#             */
/*   Updated: 2024/01/29 19:09:33 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_lencheck(char *argv)
{
	if (ft_strlen(argv) == 4)
	{
		ft_printf("Error \nMap is only a .ber!\n");
		exit(1);
	}
}

void	free_map(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	free_map_double(char **strs, char **strs2)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	i = 0;
	while (strs2[i])
	{
		free(strs2[i]);
		i++;
	}
	free(strs2);
}

void	free_exit(void *ptr, char *str, char *map)
{
	if (map == NULL)
	{
		ft_printf("%s", str);
		free(ptr);
		exit(1);
	}
	else
	{
		ft_printf("%s", str);
		free(ptr);
		free(map);
		exit(1);
	}
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*strs;
	size_t	len;
	int		i;
	int		j;

	if (s1 == NULL)
		return (s2);
	len = ft_strlen(s1) + ft_strlen(s2);
	strs = malloc(sizeof(char) * (len + 1));
	if (strs == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		strs[i] = s1[i];
	j = 0;
	while (s2[j])
		strs[i++] = s2[j++];
	strs[i] = '\0';
	free(s1);
	free(s2);
	return (strs);
}
