/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:55:39 by eandre            #+#    #+#             */
/*   Updated: 2024/01/31 18:22:46 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

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

void	spritesinit(t_game *game)
{
	int		j;

	j = 0;
	game->player.sprites.animup = generate_animup(game, j);
	game->player.sprites.animupbak = game->player.sprites.animup;
	game->player.sprites.animleft = generate_animleft(game, j);
	game->player.sprites.animleftbak = game->player.sprites.animleft;
	game->player.sprites.animright = generate_animright(game, j);
	game->player.sprites.animrightbak = game->player.sprites.animright;
	game->player.sprites.animdown = generate_animdown(game, j);
	game->player.sprites.animdownbak = game->player.sprites.animdown;
}

void	spriteswallinit(t_game *game)
{
	int		j;

	j = 0;
	game->player.sprites.animupwall = generate_animupwall(game, j);
	game->player.sprites.animupwallbak = game->player.sprites.animupwall;
	game->player.sprites.animleftwall = generate_animleftwall(game, j);
	game->player.sprites.animleftwallbak = game->player.sprites.animleftwall;
	game->player.sprites.animrightwall = generate_animrightwall(game, j);
	game->player.sprites.animrightwallbak = game->player.sprites.animrightwall;
	game->player.sprites.animdownwall = generate_animdownwall(game, j);
	game->player.sprites.animdownwallbak = game->player.sprites.animdownwall;
}
