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
		if (game)
			mlx_destroy_image(game->win.mlx, temp->content);
		free(temp);
	}
}

int	exit_hook(t_game *game)
{
	mlx_destroy_image(game->wall.win.mlx, game->wall.img);
	mlx_destroy_image(game->item.win.mlx, game->item.img);
	mlx_destroy_image(game->ground.win.mlx, game->ground.img);
	mlx_destroy_image(game->exit.win.mlx, game->exit.img);
	mlx_destroy_image(game->mobs.win.mlx, game->mobs.img);
	free_animation(game, game->player.sprites.animupbak);
	free_animation(game, game->player.sprites.animdownbak);
	free_animation(game, game->player.sprites.animrightbak);
	free_animation(game, game->player.sprites.animleftbak);
	free_map(game->map);
	mlx_destroy_window(game->win.mlx, game->win.win);
	mlx_destroy_display(game->win.mlx);
	free(game->win.mlx);
	exit(1);
}

t_player	playerinit(void)
{
	t_player	player;

	player.player_coord.x = 0;
	player.player_coord.y = 0;
	player.player_stats.itemcmp = 0;
	player.player_stats.lastmove = 1;
	player.player_stats.movecmp = 0;
	player.player_stats.curspot = '0';
	return (player);
}

void	win(t_game *game, t_coord next)
{
	if (game->map[next.y][next.x] == 'E')
	{
		if (game->player.player_stats.itemcmp == game->layout.itecmp)
		{
			ft_printf("yipee");
			exit_hook(game);
		}
	}
}

void	loose(t_game *game, t_coord next)
{
	if (game->map[next.y][next.x] == 'M')
	{
		ft_printf("NONNN");
		exit_hook(game);
	}
}

void	update_map(t_game *game, t_coord next)
{
	if (game->map[next.y][next.x] != 'C')
	{
		game->map[game->player.player_coord.y][game->player.player_coord.x]
		= game->player.player_stats.curspot;
		game->player.player_stats.curspot = game->map[next.y][next.x];
	}
	else
	{
		game->map[game->player.player_coord.y][game->player.player_coord.x]
		= '0';
		game->player.player_stats.curspot
		= game->map[game->player.player_coord.y][game->player.player_coord.x];
		game->player.player_stats.itemcmp++;
	}
	win(game, next);
	loose(game, next);
	game->map[next.y][next.x] = 'P';
	game->player.player_coord.y = next.y;
	game->player.player_coord.x = next.x;
	game->player.player_stats.movecmp++;
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

int	ft_event(int keysym, t_game *game)
{
	// char	*tmp;

	// tmp = NULL;
	if (keysym == XK_Escape)
		exit_hook(game);
	move_right(keysym, game);
	move_left(keysym, game);
	move_up(keysym, game);
	move_down(keysym, game);
	// free(tmp);
	return (0);
}

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
	// game->player = new_sprite("./textures/full_sprite.xpm", &game->win);
}

int	update(t_game *game)
{
	game->framecmp++;
	if (game->player.player_stats.lastmove == 1)
		anim_left(game, &game->player);
	if (game->player.player_stats.lastmove == 2)
		anim_up(game, &game->player);
	if (game->player.player_stats.lastmove == 3)
		anim_right(game, &game->player);
	if (game->player.player_stats.lastmove == 4)
		anim_down(game, &game->player);
	return (0);
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
	game.player = playerinit();
	game.player.player_coord = coord_finder(game.map, 'P', (t_coord){0, 0});
	check_mapresolver(map_read, &game.layout, game.player.player_coord, game.map);
	game.win = new_wind(game.layout.colcmp * 64, game.layout.lincmp  * 64, "so_long"); //game.layout.colcmp * 64, game.layout.lincmp * 64 // 3840, 2160
	if (game.win.win == NULL)
	{
		mlx_destroy_display(game.win.mlx);
		free(game.win.mlx);
		exit (1);
	}
	game.framecmp = 1;
	load_img(&game);
	free(map_read);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		j;

	j = 0;
	game = game_init(argc, argv);
	change_map_sprite(game.map);
	loadmap(game.map, &game);
	game.player.sprites.animup = generate_animup(&game, j);
	game.player.sprites.animupbak = game.player.sprites.animup;
	game.player.sprites.animleft = generate_animleft(&game, j);
	game.player.sprites.animleftbak = game.player.sprites.animleft;
	game.player.sprites.animright = generate_animright(&game, j);
	game.player.sprites.animrightbak = game.player.sprites.animright;
	game.player.sprites.animdown = generate_animdown(&game, j);
	game.player.sprites.animdownbak = game.player.sprites.animdown;
	mlx_key_hook(game.win.win, ft_event, &game);
	mlx_loop_hook(game.win.mlx, update, &game);
	mlx_hook(game.win.win, DestroyNotify, StructureNotifyMask,
		exit_hook, &game);
	mlx_loop(game.win.mlx);
	mlx_destroy_window(game.win.mlx, game.win.win);
	free(game.win.mlx);
}
