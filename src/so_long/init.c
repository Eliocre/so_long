/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:55:39 by eandre            #+#    #+#             */
/*   Updated: 2024/01/30 20:23:35 by eandre           ###   ########.fr       */
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
	layout.mobcmp = 0;
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
		free_exit(map_read, "Malloc error\n l.35 tests.c", NULL);
	game.player = playerinit();
	game.player.player_coord = coord_finder(game.map, 'P', (t_coord){0, 0});
	check_mapresolver(map_read, &game.layout, game.player.player_coord,
		game.map);
	game.win = new_wind(game.layout.colcmp * 64, game.layout.lincmp * 64,
			"so_long");
	if (game.win.win == NULL)
	{
		mlx_destroy_display(game.win.mlx);
		free(game.win.mlx);
		exit (1);
	}
	game.framecmp = 1;
	load_img(&game);
	free(map_read);
	return (game);
}

void	imgcheck(t_img img)
{
	if (img.img == NULL)
	{
		mlx_destroy_window(img.win.mlx, img.win.win);
		mlx_destroy_display(img.win.mlx);
		free(img.win.mlx);
		exit (1);
	}
}

void	load_img(t_game *game)
{
	game->wall = new_img_file(game->win, "./textures/wall.xpm");
	imgcheck(game->wall);
	game->ground = new_img_file(game->win, "./textures/ground.xpm");
	imgcheck(game->ground);
	game->groundwall = new_img_file(game->win, "./textures/wallground.xpm");
	imgcheck(game->groundwall);
	game->exitwall = new_img_file(game->win, "./textures/door.xpm");
	imgcheck(game->exitwall);
	game->exitground = new_img_file(game->win, "./textures/trapdoor.xpm");
	imgcheck(game->exitground);
	game->itemground = new_img_file(game->win, "./textures/item.xpm");
	imgcheck(game->itemground);
	game->itemwall = new_img_file(game->win, "./textures/itemwall.xpm");
	imgcheck(game->itemwall);
	game->mobswall = new_img_file(game->win, "./textures/cerberuswall.xpm");
	imgcheck(game->mobswall);
	game->mobsground = new_img_file(game->win, "./textures/cerberus.xpm");
	imgcheck(game->mobsground);
}
