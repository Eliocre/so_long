/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:07:47 by eandre            #+#    #+#             */
/*   Updated: 2024/01/31 18:15:03 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->wall.img,
			64 * i, 64 * j);
	if (c == '2')
		mlx_put_image_to_window(game->win.mlx, game->win.win,
			game->groundwall.img, 64 * i, 64 * j);
	if (c == '0')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->ground.img,
			64 * i, 64 * j);
	if (c == 'C')
		mlx_put_image_to_window(game->win.mlx, game->win.win,
			game->itemground.img, 64 * i, 64 * j);
	if (c == 'c')
		mlx_put_image_to_window(game->win.mlx, game->win.win,
			game->itemwall.img, 64 * i, 64 * j);
	if (c == 'E')
		mlx_put_image_to_window(game->win.mlx, game->win.win,
			game->exitground.img, 64 * i, 64 * j);
	if (c == 'e')
		mlx_put_image_to_window(game->win.mlx, game->win.win,
			game->exitwall.img, 64 * i, 64 * j);
}

void	casemapplayer(char c, int i, int j, t_game *game)
{
	if (c == 'P' && game->player.player_stats.curspot == '0')
		mlx_put_image_to_window(game->win.mlx, game->win.win,
			game->player.sprite.img, 64 * i, 64 * j);
	if (c == 'P' && game->player.player_stats.curspot == '2')
		mlx_put_image_to_window(game->win.mlx, game->win.win,
			game->player.spritewall.img, 64 * i, 64 * j);
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
			casemapplayer(map[i][j], j, i, game);
			j++;
		}
		i++;
	}
}

int	fill(char **tab, t_coord size, t_coord cur, char tofind)
{
	int	inturn;

	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'F'))
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
