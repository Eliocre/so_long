/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:38:38 by eandre            #+#    #+#             */
/*   Updated: 2024/01/17 14:39:22 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
