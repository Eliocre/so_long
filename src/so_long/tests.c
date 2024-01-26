/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:07:47 by eandre            #+#    #+#             */
/*   Updated: 2024/01/22 18:04:34 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

//parsing
//-needs the map in a 2D tab 

//	'M' == enemy |
//	'1' == wall	 > No walking

//	'0' == empty > walking

//	'E' == exit	 |
//	'C' == item	 > goals

//	'P' == start point

void	check_mapresolver(char *map_read, t_maplayout *layout,
t_coord player_coord, char **map)
{
	char			**mapcheck;

	mapcheck = ft_split(map_read, '\n');
	if (mapcheck == NULL)
		free_exit(map_read, "Malloc error\n l.35 tests.c", NULL);
	if (fill(mapcheck, (t_coord){layout->colcmp - 1, layout->lincmp - 1},
		player_coord, 'C') != layout->itecmp)
	{
		free_map_double(mapcheck, map);
		free_exit(map_read,
			"Error \nMap is not solvable (an item is out of reach)!\n", NULL);
	}
	free_map(mapcheck);
	mapcheck = ft_split(map_read, '\n');
	if (mapcheck == NULL)
		free_exit(map_read, "Malloc error\n l.45 tests.c", NULL);
	if (fill(mapcheck, (t_coord){layout->colcmp - 1, layout->lincmp - 1},
		player_coord, 'E') != 1)
	{
		free_map_double(mapcheck, map);
		free_exit(map_read,
			"Error \nMap is not solvable (the exit is out of reach)!\n", NULL);
	}
	free_map(mapcheck);
}

void	casemap(char c, int i, int j, t_game *game)
{
	if (c == '1')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->wall.img, 64 * i, 64 * j);
	if (c == '0')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->ground.img, 64 * i, 64 * j);
	// if (c == '2')
	// 	mlx_put_image_to_window(game->win.mlx, game->win.win, game->ground.img, 64 * i, 64 * j); for ground sprite
	if (c == 'C')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->item.img, 64 * i, 64 * j);
	// if (c == 'c')
	// 	mlx_put_image_to_window(game->win.mlx, game->win.win, game->item.img, 64 * i, 64 * j);
	if (c == 'E')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->exit.img, 64 * i, 64 * j);
	// if (c == 'e')
	// 	mlx_put_image_to_window(game->win.mlx, game->win.win, game->exit.img, 64 * i, 64 * j);
	if (c == 'M')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->mobs.img, 64 * i, 64 * j);
	// if (c == 'm')
	// 	mlx_put_image_to_window(game->win.mlx, game->win.win, game->mobs.img, 64 * i, 64 * j);
}

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

void	loadmap(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			casemap(map[i][j], j, i, game);
			j++;
		}
		i++;
	}
}

t_coord	coord_finder(char **map, char c)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
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

int	fill(char **tab, t_coord size, t_coord cur, char tofind)
{
	int	inturn;

	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'M'
		|| tab[cur.y][cur.x] == 'F'))
		return (0);
	if (tab[cur.y][cur.x] == tofind)
		inturn = 1;
	else
		inturn = 0;
	tab[cur.y][cur.x] = 'F';
	inturn += fill(tab, size, (t_coord){cur.x - 1, cur.y}, tofind);
	inturn += fill(tab, size, (t_coord){cur.x + 1, cur.y}, tofind);
	inturn += fill(tab, size, (t_coord){cur.x, cur.y - 1}, tofind);
	inturn += fill(tab, size, (t_coord){cur.x, cur.y + 1}, tofind);
	return (inturn);
}
