/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:57:09 by eandre            #+#    #+#             */
/*   Updated: 2024/01/15 18:50:51 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../src/minilibx-linux/mlx.h"
# include "../src/libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <X11/XKBlib.h>
# include <X11/Xutil.h>
# include <fcntl.h>

# ifndef DELAY
#  define DELAY 500
# endif

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		width;	
	int		height;	
}	t_win;

typedef struct s_img
{
	t_win	win;
	void	*img;
	char	*addr;
	int		he;
	int		wi;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_playstats
{
	char	curspot;
	int		itemcmp;
	int		movecmp;
	int		lastmove;
}	t_playstats;

typedef struct s_maplayout
{
	size_t	lincmp;
	size_t	colcmp;
	int		exicmp;
	int		stacmp;
	int		itecmp;
}	t_maplayout;

typedef struct s_player
{
	t_coord			player_coord;
	t_playstats		player_stats;
	t_img			sprite;
	t_img			spritewall;
}				t_player;

typedef struct s_game
{
	t_list		*test;
	t_win		win;
	t_img		wall;
	t_img		ground;
	t_img		groundwall;
	t_img		exitground;
	t_img		exitwall;
	t_img		itemground;
	t_img		itemwall;
	t_player	player;
	char		**map;
	t_maplayout	layout;
}	t_game;

t_win			new_wind(int w, int h, char *str);
t_img			new_img_file(t_win win, char *relative_path);
t_img			new_img(int w, int h, t_win window);
t_maplayout		layout_init(void);
int				charcmp(char *str, char c);
void			layout_errors(t_maplayout *layout, char *map);
void			free_exit(void *ptr, char *str, char *map);
void			checklayout(t_maplayout *layout, char *gnl, int first_last,
					char **map);
void			checkmap(int fd, t_maplayout *layout, char **map);
void			checkerror(int argc, char *argv, char **map,
					t_maplayout *layout);
void			free_map(char **strs);
void			free_map_double(char **strs, char **strs2);
t_coord			coord_finder(char **map, char c, t_coord start);
int				fill(char **tab, t_coord size, t_coord cur, char tofind);
void			check_mapresolver(char *map_read, t_maplayout *layout,
					t_coord player_coord, char **map);
void			loadmap(char **map, t_game *game);
void			ft_lencheck(char *argv);
void			change_map_sprite(char **map);
char			*ft_strjoin_free(char *s1, char *s2);
void			move_down(int keysym, t_game *game);
void			move_up(int keysym, t_game *game);
void			move_left(int keysym, t_game *game);
void			move_right(int keysym, t_game *game);
int				is_legal(t_game *game, int dir);
void			update_map(t_game *game, t_coord next);
t_game			game_init(int argc, char **argv);
void			win(t_game *game, t_coord next);
int				exit_hook(t_game *game);
void			load_img(t_game *game);
void			itemground(t_game *game);
void			itemwall(t_game *game);

#endif
