/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:01:46 by eandre            #+#    #+#             */
/*   Updated: 2024/01/31 18:50:17 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

int	exit_hook(t_game *game)
{
	mlx_destroy_image(game->wall.win.mlx, game->wall.img);
	mlx_destroy_image(game->ground.win.mlx, game->ground.img);
	mlx_destroy_image(game->groundwall.win.mlx, game->groundwall.img);
	mlx_destroy_image(game->itemground.win.mlx, game->itemground.img);
	mlx_destroy_image(game->itemwall.win.mlx, game->itemwall.img);
	mlx_destroy_image(game->exitwall.win.mlx, game->exitwall.img);
	mlx_destroy_image(game->exitground.win.mlx, game->exitground.img);
	mlx_destroy_image(game->mobswall.win.mlx, game->mobswall.img);
	mlx_destroy_image(game->mobsground.win.mlx, game->mobsground.img);
	free_animation(game, game->player.sprites.animupbak);
	free_animation(game, game->player.sprites.animdownbak);
	free_animation(game, game->player.sprites.animrightbak);
	free_animation(game, game->player.sprites.animleftbak);
	free_animation(game, game->player.sprites.animupwallbak);
	free_animation(game, game->player.sprites.animdownwallbak);
	free_animation(game, game->player.sprites.animrightwallbak);
	free_animation(game, game->player.sprites.animleftwallbak);
	free_map(game->map);
	mlx_destroy_window(game->win.mlx, game->win.win);
	mlx_destroy_display(game->win.mlx);
	free(game->win.mlx);
	exit(1);
}

void	win(t_game *game, t_coord next)
{
	if (game->map[next.y][next.x] == 'E' || game->map[next.y][next.x] == 'e')
	{
		if (game->player.player_stats.itemcmp == game->layout.itecmp)
		{
			ft_printf("\033[0;32m""YOU WIN !! \nTotal moves: %d\n""\033[0m",
			++game->player.player_stats.movecmp);
			exit_hook(game);
		}
	}
}

void	lose(t_game *game, t_coord next)
{
	if (game->map[next.y][next.x] == 'M' || game->map[next.y][next.x] == 'm')
	{
		ft_printf("\033[0;31m""YOU LOSE !!\nTotal moves: %d\n""\033[0m",
		++game->player.player_stats.movecmp);
		exit_hook(game);
	}
}
