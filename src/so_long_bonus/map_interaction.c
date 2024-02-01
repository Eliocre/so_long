/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_interaction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:16:31 by eandre            #+#    #+#             */
/*   Updated: 2024/02/01 14:31:36 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	itemwall(t_game *game)
{
	if (game->player.player_stats.curspot == '2')
		game->map[game->player.player_coord.y][game->player.player_coord.x]
			= '2';
	else if (game->player.player_stats.curspot == 'E')
		game->map[game->player.player_coord.y][game->player.player_coord.x]
			= 'E';
	else if (game->player.player_stats.curspot == 'e')
		game->map[game->player.player_coord.y][game->player.player_coord.x]
			= 'e';
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
	else if (game->player.player_stats.curspot == 'E')
		game->map[game->player.player_coord.y][game->player.player_coord.x]
			= 'E';
	else if (game->player.player_stats.curspot == 'e')
		game->map[game->player.player_coord.y][game->player.player_coord.x]
			= 'e';
	else
		game->map[game->player.player_coord.y][game->player.player_coord.x]
			= '0';
	game->player.player_stats.curspot = game->map
	[game->player.player_coord.y][game->player.player_coord.x];
	game->player.player_stats.itemcmp++;
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
