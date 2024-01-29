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
# include <stdio.h> //delete for push
# include <X11/XKBlib.h>
# include <X11/Xutil.h>
# include <fcntl.h>
//
// typedef struct s_anim
// {
// 	t_list			*frames;
// 	int				w;
// 	int				h;
// 	int				delay;
// 	int				tmp_delay;
// 	int				current_frame;
// 	long int		last_update;
// 	long int		frame_c;
// }	t_anim;
//enlever bientot
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
//
// typedef struct s_sprite
// {
// 	t_list	*anim;
// 	char	*path;
// 	t_img	sprite;
// 	int		w;
// 	int		h;
// 	int		index;
// }	t_sprite;

// typedef struct s_sprite_slice
// {
// 	int	x;
// 	int	y;
// 	int	w;
// 	int	h;
// }	t_sprite_slice;
// enlever bientot

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

typedef struct s_anim
{
	t_list		*animdown;
	t_list		*animdownbak;
	t_list		*animdownwall;
	t_list		*animup;
	t_list		*animupbak;
	t_list		*animupwall;
	t_list		*animleft;
	t_list		*animleftbak;
	t_list		*animleftwall;
	t_list		*animright;
	t_list		*animrightbak;
	t_list		*animrightwall;
}	t_anim;

typedef struct s_maplayout
{
    size_t		lincmp;
    size_t		colcmp;
    int			exicmp;
    int			stacmp;
    int			itecmp;
	int			mobcmp;
	// t_coord		player_coord;
	// t_playstats	player_stats;
}    t_maplayout;

typedef struct s_player
{
	t_coord			player_coord;
	t_playstats		player_stats;
	t_anim			sprites;
}				t_player;

typedef struct	s_game
{

	t_list		*test;
	t_win		win;
	t_img		wall;
	t_img		ground;
	t_img		exit;
	t_img		item;
	t_player	player;
	t_img		mobs;
	// t_coord		*mob;
	int			framecmp;
	char		**map;
	t_maplayout	layout;
}	t_game;

t_win			new_wind(int w, int h, char *str);
t_img			new_img_file(t_win win, char *relative_path);
t_list			*ft_lstget(t_list *lst, int index);
void			ft_lstiter_param(t_list *lst, void (*f)(void *, t_game *), t_game *ptr);
t_img			new_img(int w, int h, t_win window);
void			put_pixel_img(t_img img, int x, int y, int color);
unsigned int	get_pixel_img(t_img img, int x, int y);
t_maplayout		layout_init(void);
int				charcmp(char *str, char c);
void			layout_errors(t_maplayout *layout, char *map);
void			free_exit(void *ptr, char *str, char *map);
void			checklayout(t_maplayout *layout, char *gnl, int first_last, char **map);
void			checkmap(int fd, t_maplayout *layout, char **map);
void			checkerror(int argc, char *argv, char **map, t_maplayout *layout);
void			free_map(char **strs);
void			free_map_double(char **strs, char **strs2);
t_coord			coord_finder(char **map, char c, t_coord start);
int				fill(char **tab, t_coord size, t_coord cur, char tofind);
void			check_mapresolver(char *map_read, t_maplayout *layout, t_coord player_coord, char **map);
void			loadmap(char **map, t_game *game);
void			ft_lencheck(char *argv);
void			change_map_sprite(char **map);
t_list			*generate_animleft(t_game *game, int i);
t_list			*generate_animup(t_game *game, int i);
t_list			*generate_animdown(t_game *game, int i);
t_list			*generate_animright(t_game *game, int i);
void			anim_right(t_game *game, t_player *player);
void			anim_left(t_game *game, t_player *player);
void			anim_down(t_game *game, t_player *player);
void			anim_up(t_game *game, t_player *player);
char			*ft_strjoin_free(char *s1, char *s2);
void			casemap_enemy(char c, int i, int j, t_game *game);
void			move_down(int keysym, t_game *game);
void			move_up(int keysym, t_game *game);
void			move_left(int keysym, t_game *game);
void			move_right(int keysym, t_game *game);
int				is_legal(t_game *game, int dir);
void			update_map(t_game *game, t_coord next);

#endif
