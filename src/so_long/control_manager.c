/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:47:29 by eandre            #+#    #+#             */
/*   Updated: 2024/01/29 19:51:27 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	move_down(int keysym, t_game *game)
{
	if (keysym == XK_s)
	{
		if (is_legal(game, 4) == 0)
		{
			mlx_clear_window(game->win.mlx, game->win.win);
			update_map(game, (t_coord){game->player.player_coord.x,
				game->player.player_coord.y + 1});
			loadmap(game->map, game);
			// tmp = ft_itoa(game->player.player_stats.movecmp);
			game->player.player_stats.lastmove = 4;
			ft_printf("Moves : %d\n", game->player.player_stats.movecmp);
			// mlx_string_put(game->win.mlx, game->win.win, 27, 35, 16777215,
			//	tmp);
		}
	}
}

void	move_left(int keysym, t_game *game)
{
	if (keysym == XK_a)
	{
		if (is_legal(game, 1) == 0)
		{
			mlx_clear_window(game->win.mlx, game->win.win);
			update_map(game, (t_coord){game->player.player_coord.x - 1,
				game->player.player_coord.y});
			loadmap(game->map, game);
			// tmp = ft_itoa(game->player.player_stats.movecmp);
			game->player.player_stats.lastmove = 1;
			ft_printf("Moves : %d\n", game->player.player_stats.movecmp);
			// mlx_string_put(game->win.mlx, game->win.win, 27, 35, 16777215,
			//	tmp);
		}
	}
}

void	move_up(int keysym, t_game *game)
{
	if (keysym == XK_w)
	{
		if (is_legal(game, 2) == 0)
		{
			mlx_clear_window(game->win.mlx, game->win.win);
			update_map(game, (t_coord){game->player.player_coord.x,
				game->player.player_coord.y - 1});
			loadmap(game->map, game);
			// tmp = ft_itoa(game->player.player_stats.movecmp);
			game->player.player_stats.lastmove = 2;
			ft_printf("Moves : %d\n", game->player.player_stats.movecmp);
			// mlx_string_put(game->win.mlx, game->win.win, 27, 35, 16777215,
			// tmp);
		}
	}
}

void	move_right(int keysym, t_game *game)
{
	if (keysym == XK_d)
	{
		if (is_legal(game, 3) == 0)
		{
			mlx_clear_window(game->win.mlx, game->win.win);
			update_map(game, (t_coord){game->player.player_coord.x + 1,
				game->player.player_coord.y});
			loadmap(game->map, game);
			// tmp = ft_itoa(game->player.player_stats.movecmp);
			game->player.player_stats.lastmove = 3;
			ft_printf("Moves : %d\n", game->player.player_stats.movecmp);
			// mlx_string_put(game->win.mlx, game->win.win, 27, 35, 16777215,
			// tmp);
		}
	}
}
