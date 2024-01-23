/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:38:38 by eandre            #+#    #+#             */
/*   Updated: 2024/01/23 15:02:23 by eandre           ###   ########.fr       */
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
