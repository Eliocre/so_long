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

int	exit_hook(t_win *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(1);
}

int	ft_event(int keysym, t_win *vars)
{
	if (keysym == XK_Escape)
		exit_hook(vars);
	if (keysym == XK_d)
	{
		mlx_clear_window(vars->mlx, vars->win);
		return (0);
	}
	return (0);
}

int	update(t_list *list)
{
	if (!list)
		return (1);
	ft_lstiter(list, update_anim);
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
	t_list			*test;
	t_anim			*test2;
	t_win			mainwin;
	t_game			game;
	t_img			img;
	t_sprite		s1;
	t_sprite_slice	slice1;
	char			*relative_path;
	char			*map_read;
	// char			**map;
	t_maplayout		layout;
	t_coord			player_coord;

	map_read = NULL;
	layout = layout_init();
	checkerror(argc, argv[1], &map_read, &layout);
	game.map = ft_split(map_read, '\n');
	if (game.map == NULL)
		free_exit(map_read, "Malloc error\n l.35 tests.c", NULL);
	player_coord = coord_finder(game.map, 'P');
	check_mapresolver(map_read, &layout, player_coord);
	free(map_read);
	relative_path = "./textures/yipee.xpm";
	mainwin = new_wind(1920, 1080, "amongus");
	if (mainwin.win == NULL)
	{
		mlx_destroy_display(mainwin.mlx);
		free(mainwin.mlx);
		return (1);
	}
	game.win = mainwin;
	game.wall = new_img_file(mainwin, "./textures/wall.xpm");
	game.ground = new_img_file(mainwin, "./textures/sol.xpm");
	game.exit = new_img_file(mainwin, "./textures/exit.xpm");
	game.item = new_img_file(mainwin, "./textures/item.xpm");
	s1 = new_sprite("./textures/full_sprite.xpm", &mainwin);
	if (s1.sprite.img == NULL)
	{
		destroy_sprite(s1);
		mlx_destroy_window(mainwin.mlx, mainwin.win);
		return (1);
	}
	game.player = s1;
	loadmap(game.map, &game);
	img = new_img_file(mainwin, relative_path);
	if (img.img == NULL)
	{
		mlx_destroy_window(mainwin.mlx, mainwin.win);
		mlx_destroy_display(mainwin.mlx);
		free(mainwin.mlx);
		return (1);
	}
	slice1 = (t_sprite_slice){0, 0, 64, 64};
	test2 = slice_sprite(s1, slice1, 4, 6000);
	if (test2 == NULL)
		return (1);
	test = ft_lstnew(test2);
	if (test == NULL)
		return (1);
	ft_lstadd_back(&s1.anim, test);
	mlx_loop_hook(mainwin.mlx, update, s1.anim);
	// mlx_put_image_to_window(mainwin.mlx, mainwin.win, img.img, 0, 0);
	free(s1.path);
	mlx_destroy_image(s1.sprite.win.mlx, s1.sprite.img);
	mlx_destroy_image(mainwin.mlx, img.img);
	mlx_key_hook(mainwin.win, ft_event, &mainwin);
	mlx_hook(mainwin.win, DestroyNotify, StructureNotifyMask,
		exit_hook, &mainwin);
	// mlx_key_hook(mainwin.win, ft_event, &s1.sprite.win);
	// mlx_hook(mainwin.win, DestroyNotify, StructureNotifyMask,
	// 	exit_hook, &s1.sprite.win);
	mlx_loop(mainwin.mlx);
	// need to find a way to put sprite into mainwin
	mlx_destroy_window(mainwin.mlx, mainwin.win);
	free(mainwin.mlx);
}
