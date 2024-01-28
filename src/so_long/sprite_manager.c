/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:00:39 by eandre            #+#    #+#             */
/*   Updated: 2024/01/08 18:17:01 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// t_sprite	new_sprite(char *path, t_win *win)
// {
// 	t_img	img;

// 	img = new_img_file(*win, path);
// 	return ((t_sprite){NULL, ft_strdup(path),
// 		img, img.wi, img.he, 0});
// }

// void	destroy_sprite(t_sprite s)
// {
// 	free(s.path);
// 	mlx_destroy_image(s.sprite.win.mlx, s.sprite.img);
// 	free(s.anim);
// }

// t_anim	*slice_sprite(t_sprite s, t_sprite_slice slice, int frames, int delay)
// {
// 	int		i;
// 	t_anim	*an;

// 	an = ft_calloc(1, sizeof(t_anim));
// 	if (an == NULL)
// 		exit(1);
// 	*an = (t_anim){NULL, slice.w, slice.h, delay, 0, 0, 0, 0};
// 	i = 0;
// 	while (i < frames)
// 	{
// 		add_frame(an, s, slice);
// 		if (an->frames == NULL)
// 			return (NULL);
// 		slice.x += slice.w;
// 		if (slice.x >= s.w)
// 		{
// 			slice.x = 0;
// 			slice.y += slice.h;
// 		}
// 		i++;
// 	}
// 	return (an);
// }

// void	add_frame(t_anim *an, t_sprite s, t_sprite_slice slice)
// {
// 	t_img	*frame;
// 	t_list	*lst;
// 	int		i;
// 	int		j;

// 	frame = ft_calloc(1, sizeof(t_img));
// 	if (frame == NULL)
// 		exit(1);
// 	*frame = new_img(slice.w, slice.h, s.sprite.win);
// 	if (frame->img == NULL)
// 		exit(1);
// 	i = 0;
// 	while (i < slice.w)
// 	{
// 		j = -1;
// 		while (++j < slice.h)
// 			put_pixel_img(*frame, slice.w - j, i,
// 				get_pixel_img(s.sprite, slice.x + j, slice.y + i));
// 		i++;
// 	}
// 	lst = ft_lstnew(frame);
// 	if (lst == NULL)
// 		exit(1);
// 	ft_lstadd_back(&an->frames, lst);
// }

// void	update_anim(void *ptr, t_game *game)
// {
// 	t_anim	*an;
// 	t_img	*img;

// 	an = (t_list *)ptr;
// 	if (an == NULL)
// 		exit(1);
// 	if (an->tmp_delay++ == an->delay)
// 	{
// 		an->tmp_delay = 0;
// 		an->current_frame++;
// 		an->current_frame %= ft_lstsize(an->frames);
// 		img = (t_img *)ft_lstget(an->frames, an->current_frame)->content;
// 		mlx_put_image_to_window(img->win.mlx, img->win.win, img->img, game->.player_coord.x * 64, game->layout.player_coord.y * 64);
// 	}
// }
