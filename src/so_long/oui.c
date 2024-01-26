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

void	free_animation(t_game *game, t_list *start)
{
	t_list		*temp;

	temp = NULL;
	while (start)
	{
		temp = start;
		start = start->next;
		if (game != NULL)
			mlx_destroy_image(game->win.mlx, temp->content);
		free(temp);
	}
}

// ft_lstclear(&game->player.anim, free);
int	exit_hook(t_game *game)
{
	mlx_destroy_image(game->wall.win.mlx, game->wall.img);
	mlx_destroy_image(game->item.win.mlx, game->item.img);
	mlx_destroy_image(game->ground.win.mlx, game->ground.img);
	mlx_destroy_image(game->exit.win.mlx, game->exit.img);
	destroy_sprite(game->player);
	// free_animation(game, game->animation->frames);
	free_map(game->map);
	mlx_destroy_window(game->win.mlx, game->win.win);
	mlx_destroy_display(game->win.mlx);
	free(game->win.mlx);
	exit(1);
}

int	update(t_game *game) //t_list *list
{
	if (!game->player.anim)
		return (1);
	if (game->map[game->layout.player_coord.y - 1][game->layout.player_coord.x] &&
		game->map[game->layout.player_coord.y - 1][game->layout.player_coord.x] == '1')
	ft_lstiter_param(game->player.anim, update_anim, game);
	return (0);
}

void	update_map(t_game *game, t_coord next)
{
	if (game->map[next.y][next.x] != 'C')
	{
		game->map[game->layout.player_coord.y][game->layout.player_coord.x] = game->layout.player_stats.curspot;
		game->layout.player_stats.curspot = game->map[next.y][next.x];
	}
	else
	{
		game->map[game->layout.player_coord.y][game->layout.player_coord.x] = '0';
		game->layout.player_stats.curspot = game->map[game->layout.player_coord.y][game->layout.player_coord.x];
		game->layout.player_stats.itemcmp++;
	}
	if (game->map[next.y][next.x] == 'E')
	{
		if (game->layout.player_stats.itemcmp == game->layout.itecmp)
		{
			ft_printf("yipee");
			exit_hook(game);
		}
	}
	if (game->map[next.y][next.x] == 'M')
	{
		ft_printf("NONNN");
		exit_hook(game);
	}
	game->map[next.y][next.x] = 'P';
	game->layout.player_coord.y = next.y;
	game->layout.player_coord.x = next.x;
	game->layout.player_stats.movecmp++;
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
	char	*tmp;

	tmp = NULL;
	if (keysym == XK_Escape)
		exit_hook(game);
	if (keysym == XK_a)
	{
		if (is_legal(game, 1) == 0)
		{
			mlx_clear_window(game->win.mlx, game->win.win);
			update_map(game, (t_coord){game->layout.player_coord.x - 1, game->layout.player_coord.y});
			loadmap(game->map, game);
			tmp = ft_itoa(game->layout.player_stats.movecmp);
			mlx_string_put(game->win.mlx, game->win.win, 27, 35, 16777215, tmp);
		}
	}
	if (keysym == XK_w)
	{
		if (is_legal(game, 2) == 0)
		{
			mlx_clear_window(game->win.mlx, game->win.win);
			update_map(game, (t_coord){game->layout.player_coord.x, game->layout.player_coord.y - 1});
			loadmap(game->map, game);
			tmp = ft_itoa(game->layout.player_stats.movecmp);
			mlx_string_put(game->win.mlx, game->win.win, 27, 35, 16777215, tmp);
		}
	}
	if (keysym == XK_d)
	{
		if (is_legal(game, 3) == 0)
		{
			mlx_clear_window(game->win.mlx, game->win.win);
			update_map(game, (t_coord){game->layout.player_coord.x + 1, game->layout.player_coord.y});
			loadmap(game->map, game);
			tmp = ft_itoa(game->layout.player_stats.movecmp);
			mlx_string_put(game->win.mlx, game->win.win, 27, 35, 16777215, tmp);
		}
	}
	if (keysym == XK_s)
	{
		if (is_legal(game, 4) == 0)
		{
			mlx_clear_window(game->win.mlx, game->win.win);
			update_map(game, (t_coord){game->layout.player_coord.x, game->layout.player_coord.y + 1});
			loadmap(game->map, game);
			tmp = ft_itoa(game->layout.player_stats.movecmp);
			mlx_string_put(game->win.mlx, game->win.win, 27, 35, 16777215, tmp);
		}
	}
	free(tmp);
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

//today:
//if thing: load back after going on it with the player #done#
//player inventory for items #done#
//lose and win #done#
//

void	imgcheck(t_img img)
{
	if (img.img == NULL)
	{
		mlx_destroy_window(img.win.mlx, img.win.win);
		mlx_destroy_display(img.win.mlx);
		free(img.win.mlx);
		exit (1);
	}
}

void	load_img(t_game *game)
{
	game->wall = new_img_file(game->win, "./textures/wall.xpm");
	imgcheck(game->wall);
	game->ground = new_img_file(game->win, "./textures/sol.xpm");
	imgcheck(game->ground);
	game->exit = new_img_file(game->win, "./textures/exit.xpm");
	imgcheck(game->exit);
	game->item = new_img_file(game->win, "./textures/item.xpm");
	imgcheck(game->item);
	game->mobs = new_img_file(game->win, "./textures/mob.xpm");
	imgcheck(game->mobs);
	game->player = new_sprite("./textures/full_sprite.xpm", &game->win);
}


t_game	game_init(int argc, char **argv)
{
	t_game	game;
	char	*map_read;

	map_read = NULL;
	game.layout = layout_init();
	checkerror(argc, argv[1], &map_read, &game.layout);
	game.map = ft_split(map_read, '\n');
	if (game.map == NULL)
		free_exit(map_read, "Malloc error\n l.35 tests.c", NULL);
	game.layout.player_coord = coord_finder(game.map, 'P');
	check_mapresolver(map_read, &game.layout, game.layout.player_coord, game.map);
	game.win = new_wind((game.layout.colcmp - 1) * 64, game.layout.lincmp * 64, "so_long"); //game.layout.colcmp * 64, game.layout.lincmp * 64 // 3840, 2160
	if (game.win.win == NULL)
	{
		mlx_destroy_display(game.win.mlx);
		free(game.win.mlx);
		exit (1);
	}
	load_img(&game);
	free(map_read);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game			game;
	t_sprite_slice	slice1;

	game = game_init(argc, argv);
	change_map_sprite(game.map);
	loadmap(game.map, &game);
	slice1 = (t_sprite_slice){0, 64, 64, 64};
	game.animation = slice_sprite(game.player, slice1, 15, 200);
	if (game.animation == NULL)
		return (1);
	game.test = ft_lstnew(game.animation);
	if (game.test == NULL)
		return (1);
	ft_lstadd_back(&game.player.anim, game.test);
	mlx_key_hook(game.win.win, ft_event, &game);

	mlx_loop_hook(game.win.mlx, update, &game);
	mlx_hook(game.win.win, DestroyNotify, StructureNotifyMask,
		exit_hook, &game);
	mlx_loop(game.win.mlx);
	mlx_destroy_window(game.win.mlx, game.win.win);
	free(game.win.mlx);
}
