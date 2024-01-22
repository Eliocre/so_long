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

int	exit_hook(t_game *game)
{
	// ft_lstclear(&game->player.anim, free);
	mlx_destroy_image(game->wall.win.mlx, game->wall.img);
	mlx_destroy_image(game->item.win.mlx, game->item.img);
	mlx_destroy_image(game->ground.win.mlx, game->ground.img);
	mlx_destroy_image(game->exit.win.mlx, game->exit.img);
	destroy_sprite(game->player);
	free_map(game->map);
	// ft_lstclear(&game->test, free);
	// ft_lstclear(&game->animation->frames, free);
	mlx_destroy_window(game->win.mlx, game->win.win);
	mlx_destroy_display(game->win.mlx);
	free(game->win.mlx);
	exit(1);
}

int	update(t_game *game) //t_list *list
{
	if (!game->player.anim)
		return (1);
	ft_lstiter_param(game->player.anim, update_anim, game);
	return (0);
}

void	update_map(t_game *game, t_coord next)
{
	game->map[game->layout.player_coord.y][game->layout.player_coord.x] = '0';
	game->map[next.y][next.x] = 'P';
	game->layout.player_coord.y = next.y;
	game->layout.player_coord.x = next.x;
}

int	is_legal(t_game *game, int dir)
{
	if (game->map[game->layout.player_coord.y][game->layout.player_coord.x - 1] == '1'
	&& dir == 1)
		return (1);
	if (game->map[game->layout.player_coord.y - 1][game->layout.player_coord.x] == '1'
	&& dir == 2)
		return (1);
	if (game->map[game->layout.player_coord.y][game->layout.player_coord.x + 1] == '1'
	&& dir == 3)
		return (1);
	if (game->map[game->layout.player_coord.y + 1][game->layout.player_coord.x] == '1'
	&& dir == 4)
		return (1);
	return (0);
}

int	ft_event(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		exit_hook(game);
	if (keysym == XK_a)
	{
		if (is_legal(game, 1) == 0)
		{
			mlx_clear_window(game->win.mlx, game->win.win);
			update_map(game, (t_coord){game->layout.player_coord.x - 1, game->layout.player_coord.y});
			loadmap(game->map, game);
		}
	}
	if (keysym == XK_w)
	{
		if (is_legal(game, 2) == 0)
		{
			mlx_clear_window(game->win.mlx, game->win.win);
			update_map(game, (t_coord){game->layout.player_coord.x, game->layout.player_coord.y - 1});
			loadmap(game->map, game);
		}
	}
	if (keysym == XK_d)
	{
		if (is_legal(game, 3) == 0)
		{
			mlx_clear_window(game->win.mlx, game->win.win);
			update_map(game, (t_coord){game->layout.player_coord.x + 1, game->layout.player_coord.y});
			loadmap(game->map, game);
		}
	}
	if (keysym == XK_s)
	{
		if (is_legal(game, 4) == 0)
		{
			mlx_clear_window(game->win.mlx, game->win.win);
			update_map(game, (t_coord){game->layout.player_coord.x, game->layout.player_coord.y + 1});
			loadmap(game->map, game);
		}
	}
	return (0);
}

// load map :
// -each char = sprite :
// --'1' == wall
// --'0' == ground
// --'P' == player
// --'C' == item
// --'M' == mob
// --'E' == exit

int	main(int argc, char **argv)
{
	// t_list			*test;
	// t_anim			*test2;
	t_game			game;
	t_sprite_slice	slice1;
	char			*map_read;

	map_read = NULL;
	game.layout = layout_init();
	checkerror(argc, argv[1], &map_read, &game.layout);
	game.map = ft_split(map_read, '\n');
	if (game.map == NULL)
		free_exit(map_read, "Malloc error\n l.35 tests.c", NULL);
	game.layout.player_coord = coord_finder(game.map, 'P');
	check_mapresolver(map_read, &game.layout, game.layout.player_coord, game.map);
	free(map_read);
	// relative_path = "./textures/yipee.xpm";
	game.win = new_wind(1920, 1080, "amongus");
	if (game.win.win == NULL)
	{
		mlx_destroy_display(game.win.mlx);
		free(game.win.mlx);
		return (1);
	}
	game.wall = new_img_file(game.win, "./textures/wall.xpm");
	game.ground = new_img_file(game.win, "./textures/sol.xpm");
	game.exit = new_img_file(game.win, "./textures/exit.xpm");
	game.item = new_img_file(game.win, "./textures/item.xpm");
	game.mobs = new_img_file(game.win, "./textures/mob.xpm");
	game.player = new_sprite("./textures/full_sprite.xpm", &game.win);
	if (game.player.sprite.img == NULL)
	{
		destroy_sprite(game.player);
		mlx_destroy_window(game.win.mlx, game.win.win);
		return (1);
	}
	loadmap(game.map, &game);
	// img = new_img_file(mainwin, relative_path);
	// if (img.img == NULL)
	// {
	// 	mlx_destroy_window(mainwin.mlx, mainwin.win);
	// 	mlx_destroy_display(mainwin.mlx);
	// 	free(mainwin.mlx);
	// 	return (1);
	// }
	slice1 = (t_sprite_slice){0, 0, 64, 64};
	game.animation = slice_sprite(game.player, slice1, 4, 500);
	if (game.animation == NULL)
		return (1);
	game.test = ft_lstnew(game.animation);
	if (game.test == NULL)
		return (1);
	ft_lstadd_back(&game.player.anim, game.test);
	mlx_key_hook(game.win.win, ft_event, &game);
	mlx_loop_hook(game.win.mlx, update, &game); //.player.anim
	// mlx_put_image_to_window(mainwin.mlx, mainwin.win, img.img, 0, 0);
	// free(game.player.path);
	// mlx_destroy_image(game.player.sprite.win.mlx, game.player.sprite.img);
	// mlx_destroy_image(mainwin.mlx, img.img);
	mlx_hook(game.win.win, DestroyNotify, StructureNotifyMask,
		exit_hook, &game);
	// mlx_key_hook(mainwin.win, ft_event, &s1.sprite.win);
	// mlx_hook(mainwin.win, DestroyNotify, StructureNotifyMask,
	// 	exit_hook, &s1.sprite.win);
	mlx_loop(game.win.mlx);
	// need to find a way to put sprite into mainwin
	mlx_destroy_window(game.win.mlx, game.win.win);
	free(game.win.mlx);
}
