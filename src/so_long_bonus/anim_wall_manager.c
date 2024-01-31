/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_wall_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:51:01 by eandre            #+#    #+#             */
/*   Updated: 2024/01/31 18:22:22 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	anim_upwall(t_game *game, t_player *player)
{
	t_player	*temp;

	temp = player;
	if (game->framecmp % (DELAY) == 0)
		temp->sprites.animupwall = temp->sprites.animupwall->next;
	if (!temp->sprites.animupwall)
		temp->sprites.animupwall = temp->sprites.animupwallbak;
	mlx_put_image_to_window(game->win.mlx, game->win.win,
		temp->sprites.animupwall->content,
		temp->player_coord.x * 64, temp->player_coord.y * 64);
}

void	anim_downwall(t_game *game, t_player *player)
{
	t_player	*temp;

	temp = player;
	if (game->framecmp % (DELAY) == 0)
		temp->sprites.animdownwall = temp->sprites.animdownwall->next;
	if (!temp->sprites.animdownwall)
		temp->sprites.animdownwall = temp->sprites.animdownwallbak;
	mlx_put_image_to_window(game->win.mlx, game->win.win,
		temp->sprites.animdownwall->content,
		temp->player_coord.x * 64, temp->player_coord.y * 64);
}

void	anim_leftwall(t_game *game, t_player *player)
{
	t_player	*temp;

	temp = player;
	if (game->framecmp % (DELAY) == 0)
		temp->sprites.animleftwall = temp->sprites.animleftwall->next;
	if (!temp->sprites.animleftwall)
		temp->sprites.animleftwall = temp->sprites.animleftwallbak;
	mlx_put_image_to_window(game->win.mlx, game->win.win,
		temp->sprites.animleftwall->content,
		temp->player_coord.x * 64, temp->player_coord.y * 64);
}

void	anim_rightwall(t_game *game, t_player *player)
{
	t_player	*temp;

	temp = player;
	if (game->framecmp % (DELAY) == 0)
		temp->sprites.animrightwall = temp->sprites.animrightwall->next;
	if (!temp->sprites.animrightwall)
		temp->sprites.animrightwall = temp->sprites.animrightwallbak;
	mlx_put_image_to_window(game->win.mlx, game->win.win,
		temp->sprites.animrightwall->content,
		temp->player_coord.x * 64, temp->player_coord.y * 64);
}
