/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:47:29 by eandre            #+#    #+#             */
/*   Updated: 2024/02/01 14:51:43 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	move_down(int keysym, t_game *game)
{
	if (keysym == XK_s)
	{
		if (is_legal(game, 4) == 0)
		{
			update_map(game, (t_coord){game->player.player_coord.x,
				game->player.player_coord.y + 1});
			loadmap(game->map, game);
			game->player.player_stats.lastmove = 4;
			ft_printf("Moves : %d\n", game->player.player_stats.movecmp);
		}
	}
}

void	move_left(int keysym, t_game *game)
{
	if (keysym == XK_a)
	{
		if (is_legal(game, 1) == 0)
		{
			update_map(game, (t_coord){game->player.player_coord.x - 1,
				game->player.player_coord.y});
			loadmap(game->map, game);
			game->player.player_stats.lastmove = 1;
			ft_printf("Moves : %d\n", game->player.player_stats.movecmp);
		}
	}
}

void	move_up(int keysym, t_game *game)
{
	if (keysym == XK_w)
	{
		if (is_legal(game, 2) == 0)
		{
			update_map(game, (t_coord){game->player.player_coord.x,
				game->player.player_coord.y - 1});
			loadmap(game->map, game);
			game->player.player_stats.lastmove = 2;
			ft_printf("Moves : %d\n", game->player.player_stats.movecmp);
		}
	}
}

void	move_right(int keysym, t_game *game)
{
	if (keysym == XK_d)
	{
		if (is_legal(game, 3) == 0)
		{
			update_map(game, (t_coord){game->player.player_coord.x + 1,
				game->player.player_coord.y});
			loadmap(game->map, game);
			game->player.player_stats.lastmove = 3;
			ft_printf("Moves : %d\n", game->player.player_stats.movecmp);
		}
	}
}
