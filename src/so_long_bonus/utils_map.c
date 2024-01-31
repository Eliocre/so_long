/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:22:12 by eandre            #+#    #+#             */
/*   Updated: 2024/01/31 18:23:07 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	change_map_sprite(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && map[i - 1][j] && map[i - 1][j] == '1')
				map[i][j] = '2';
			else if (map[i][j] == 'M' && map[i - 1][j] && map[i - 1][j] == '1')
				map[i][j] = 'm';
			else if (map[i][j] == 'E' && map[i - 1][j] && map[i - 1][j] == '1')
				map[i][j] = 'e';
			else if (map[i][j] == 'C' && map[i - 1][j] && map[i - 1][j] == '1')
				map[i][j] = 'c';
			j++;
		}
		i++;
	}
}

t_coord	coord_finder(char **map, char c, t_coord start)
{
	int	i;
	int	j;
	int	bool_;

	bool_ = 0;
	i = start.y;
	while (map[i])
	{
		if (bool_ == 0)
		{
			j = start.x;
			bool_ = 1;
		}
		else
			j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return ((t_coord){j, i});
			j++;
		}
		i++;
	}
	return ((t_coord){0, 0});
}
