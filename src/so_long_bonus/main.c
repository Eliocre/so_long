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

#include "../../include/so_long_bonus.h"

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
	lose(game, next);
	game->map[next.y][next.x] = 'P';
	game->player.player_coord.y = next.y;
	game->player.player_coord.x = next.x;
	game->player.player_stats.movecmp++;
}

int	ft_event(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		ft_printf("\033[0;32m""Game ended early !\n""\033[0m");
		exit_hook(game);
	}
	move_right(keysym, game);
	move_left(keysym, game);
	move_up(keysym, game);
	move_down(keysym, game);
	return (0);
}

int	update(t_game *game)
{
	game->framecmp++;
	if (game->player.player_stats.lastmove == 1
		&& game->player.player_stats.curspot == '2')
		anim_leftwall(game, &game->player);
	if (game->player.player_stats.lastmove == 1
		&& game->player.player_stats.curspot != '2')
		anim_left(game, &game->player);
	if (game->player.player_stats.lastmove == 2
		&& game->player.player_stats.curspot == '2')
		anim_upwall(game, &game->player);
	if (game->player.player_stats.lastmove == 2
		&& game->player.player_stats.curspot != '2')
		anim_up(game, &game->player);
	if (game->player.player_stats.lastmove == 3
		&& game->player.player_stats.curspot == '2')
		anim_rightwall(game, &game->player);
	if (game->player.player_stats.lastmove == 3
		&& game->player.player_stats.curspot != '2')
		anim_right(game, &game->player);
	if (game->player.player_stats.lastmove == 4)
		anim_down(game, &game->player);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = game_init(argc, argv);
	change_map_sprite(game.map);
	loadmap(game.map, &game);
	spritesinit(&game);
	spriteswallinit(&game);
	mlx_key_hook(game.win.win, ft_event, &game);
	mlx_loop_hook(game.win.mlx, update, &game);
	mlx_hook(game.win.win, DestroyNotify, StructureNotifyMask,
		exit_hook_cross, &game);
	mlx_loop(game.win.mlx);
	mlx_destroy_window(game.win.mlx, game.win.win);
	free(game.win.mlx);
}
