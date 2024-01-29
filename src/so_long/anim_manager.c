/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:03:23 by eandre            #+#    #+#             */
/*   Updated: 2024/01/29 19:07:11 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	anim_up(t_game *game, t_player *player)
{
	t_player	*temp;

	temp = player;
	if (game->framecmp % (200) == 0)
		temp->sprites.animup = temp->sprites.animup->next;
	if (!temp->sprites.animup)
		temp->sprites.animup = temp->sprites.animupbak;
	mlx_put_image_to_window(game->win.mlx, game->win.win,
		temp->sprites.animup->content,
		temp->player_coord.x * 64, temp->player_coord.y * 64);
}

void	anim_down(t_game *game, t_player *player)
{
	t_player	*temp;

	temp = player;
	if (game->framecmp % (200) == 0)
		temp->sprites.animdown = temp->sprites.animdown->next;
	if (!temp->sprites.animdown)
		temp->sprites.animdown = temp->sprites.animdownbak;
	mlx_put_image_to_window(game->win.mlx, game->win.win,
		temp->sprites.animdown->content,
		temp->player_coord.x * 64, temp->player_coord.y * 64);
}

void	anim_left(t_game *game, t_player *player)
{
	t_player	*temp;

	temp = player;
	if (game->framecmp % (200) == 0)
		temp->sprites.animleft = temp->sprites.animleft->next;
	if (!temp->sprites.animleft)
		temp->sprites.animleft = temp->sprites.animleftbak;
	mlx_put_image_to_window(game->win.mlx, game->win.win,
		temp->sprites.animleft->content,
		temp->player_coord.x * 64, temp->player_coord.y * 64);
}

void	anim_right(t_game *game, t_player *player)
{
	t_player	*temp;

	temp = player;
	if (game->framecmp % (200) == 0)
		temp->sprites.animright = temp->sprites.animright->next;
	if (!temp->sprites.animright)
		temp->sprites.animright = temp->sprites.animrightbak;
	mlx_put_image_to_window(game->win.mlx, game->win.win,
		temp->sprites.animright->content,
		temp->player_coord.x * 64, temp->player_coord.y * 64);
}
