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

typedef struct s_anim
{
	t_list			*frames;
	int				w;
	int				h;
	int				delay;
	int				tmp_delay;
	int				current_frame;
	long int		last_update;
	long int		frame_c;
}	t_anim;

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

typedef struct s_sprite
{
	t_list	*anim;
	char	*path;
	t_img	sprite;
	int		w;
	int		h;
	int		index;
}	t_sprite;

typedef struct s_sprite_slice
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_sprite_slice;

typedef struct	s_game
{
	t_win		win;
	t_img		image;
	t_sprite	player;
	t_sprite	mobs;
}	t_game;

typedef struct s_maplayout
{
    size_t    lincmp;
    size_t    colcmp;
    int        exicmp;
    int        stacmp;
    int        itecmp;
}    t_maplayout;

void			add_frame(t_anim *an, t_sprite s, t_sprite_slice slice);
void			destroy_sprite(t_sprite s);
t_anim			*slice_sprite(t_sprite s, t_sprite_slice slice, int frames, int delay);
t_win			new_wind(int w, int h, char *str);
void			update_anim(void *ptr);
t_img			new_img_file(t_win win, char *relative_path);
t_list			*ft_lstget(t_list *lst, int index);
void			ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void * ptr);
t_sprite		new_sprite(char *path, t_win *win);
t_img			new_img(int w, int h, t_win window);
void			put_pixel_img(t_img img, int x, int y, int color);
unsigned int	get_pixel_img(t_img img, int x, int y);
t_maplayout		layout_init(void);
int				charcmp(char *str, char c);
void			put_img_to_img(t_img dst, t_img src, int x, int y);
void			layout_errors(t_maplayout *layout, char *map);
void			free_exit(void *ptr, char *str, char *map);
void			checklayout(t_maplayout *layout, char *gnl, int first_last, char **map);
void			checkmap(int fd, t_maplayout *layout, char **map);
void			checkerror(int argc, char *argv, char **map);
void			free_map(char **strs);

#endif