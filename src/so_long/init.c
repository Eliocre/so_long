/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:55:39 by eandre            #+#    #+#             */
/*   Updated: 2024/02/01 17:06:00 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_maplayout	layout_init(void)
{
	t_maplayout	layout;

	layout.lincmp = 0;
	layout.colcmp = 0;
	layout.exicmp = 0;
	layout.stacmp = 0;
	layout.itecmp = 0;
	return (layout);
}

t_player	playerinit(void)
{
	t_player	player;

	player.player_coord.x = 0;
	player.player_coord.y = 0;
	player.player_stats.itemcmp = 0;
	player.player_stats.lastmove = 1;
	player.player_stats.movecmp = 0;
	player.player_stats.curspot = '0';
	return (player);
}

t_game	game_init(int argc, char **argv)
{
	t_game	game;
	char	*map_read;

	map_read = NULL;
	game.layout = layout_init();
	checkerror(argc, argv[1], &map_read, &game.layout);
	game.map = ft_split(map_read, '\n');
	if (game.map == NULL)
		free_exit(map_read, "Malloc error\n l.50 init.c", NULL);
	game.player = playerinit();
	game.player.player_coord = coord_finder(game.map, 'P', (t_coord){0, 0});
	check_mapresolver(map_read, &game.layout, game.player.player_coord,
		game.map);
	game.win = new_wind(game.layout.colcmp * 64, game.layout.lincmp * 64,
			"so_long");
	free(map_read);
	if (game.win.win == NULL)
	{
		ft_printf("Window generation failed!");
		free_map(game.map);
		free(game.win.mlx);
		exit (1);
	}
	load_img(&game);
	return (game);
}
