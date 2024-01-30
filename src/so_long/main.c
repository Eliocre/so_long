/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:04:58 by eandre            #+#    #+#             */
/*   Updated: 2024/01/15 18:49:51 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//-lmlx -lXext -lX11
#include "../../include/so_long.h"

void	itemwall(t_game *game)
{
	if (game->player.player_stats.curspot == '2')
		game->map[game->player.player_coord.y][game->player.player_coord.x]
			= '2';
	else
		game->map[game->player.player_coord.y][game->player.player_coord.x]
			= '0';
	game->player.player_stats.curspot = '2';
	game->player.player_stats.itemcmp++;
}

void	itemground(t_game *game)
{
	if (game->player.player_stats.curspot == '2')
		game->map[game->player.player_coord.y][game->player.player_coord.x]
			= '2';
	else
		game->map[game->player.player_coord.y][game->player.player_coord.x]
			= '0';
	game->player.player_stats.curspot = game->map
	[game->player.player_coord.y][game->player.player_coord.x];
	game->player.player_stats.itemcmp++;
}

void	update_map(t_game *game, t_coord next)
{
	if (game->map[next.y][next.x] == 'C')
		itemground(game);
	else if (game->map[next.y][next.x] == 'c')
		itemwall(game);
	else
	{
		game->map[game->player.player_coord.y][game->player.player_coord.x]
			= game->player.player_stats.curspot;
		game->player.player_stats.curspot = game->map[next.y][next.x];
	}
	win(game, next);
	loose(game, next);
	game->map[next.y][next.x] = 'P';
	game->player.player_coord.y = next.y;
	game->player.player_coord.x = next.x;
	game->player.player_stats.movecmp++;
}

int	is_legal(t_game *game, int dir)
{
	if (game->map[game->player.player_coord.y]
		[game->player.player_coord.x - 1] == '1' && dir == 1)
		return (1);
	if (game->map[game->player.player_coord.y - 1]
		[game->player.player_coord.x] == '1' && dir == 2)
		return (1);
	if (game->map[game->player.player_coord.y]
		[game->player.player_coord.x + 1] == '1' && dir == 3)
		return (1);
	if (game->map[game->player.player_coord.y + 1]
		[game->player.player_coord.x] == '1' && dir == 4)
		return (1);
	return (0);
}

int	ft_event(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		exit_hook(game);
	move_right(keysym, game);
	move_left(keysym, game);
	move_up(keysym, game);
	move_down(keysym, game);
	return (0);
}

int	update(t_game *game)
{
	game->framecmp++;
	if (game->player.player_stats.lastmove == 1)
		anim_left(game, &game->player);
	else if (game->player.player_stats.lastmove == 1
		&& game->player.player_stats.curspot == '2')
		anim_leftwall(game, &game->player);
	if (game->player.player_stats.lastmove == 2)
		anim_up(game, &game->player);
	else if (game->player.player_stats.lastmove == 2
		&& game->player.player_stats.curspot == '2')
		anim_upwall(game, &game->player);
	if (game->player.player_stats.lastmove == 3)
		anim_right(game, &game->player);
	else if (game->player.player_stats.lastmove == 3
		&& game->player.player_stats.curspot == '2')
		anim_rightwall(game, &game->player);
	if (game->player.player_stats.lastmove == 4)
		anim_down(game, &game->player);
	return (0);
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

int	main(int argc, char **argv)
{
	t_game	game;

	game = game_init(argc, argv);
	change_map_sprite(game.map);
	loadmap(game.map, &game);
	spritesinit(&game);
	mlx_key_hook(game.win.win, ft_event, &game);
	mlx_loop_hook(game.win.mlx, update, &game);
	mlx_hook(game.win.win, DestroyNotify, StructureNotifyMask,
		exit_hook, &game);
	mlx_loop(game.win.mlx);
	mlx_destroy_window(game.win.mlx, game.win.win);
	free(game.win.mlx);
}
