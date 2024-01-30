/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:00:35 by eandre            #+#    #+#             */
/*   Updated: 2024/01/08 18:16:52 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img = mlx_new_image(window.mlx, w, h);
	if (image.img == NULL)
		return (image);
	image.addr = mlx_get_data_addr(image.img, &(image.bits_per_pixel),
			&(image.line_length), &(image.endian));
	image.wi = w;
	image.he = h;
	return (image);
}

t_img	new_img_file(t_win win, char *relative_path)
{
	t_img	img;

	img.win = win;
	img.img = mlx_xpm_file_to_image(win.mlx, relative_path, &img.wi, &img.he);
	if (img.img == NULL)
		write(2, "File could not be read\n", 23);
	else
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
	return (img);
}
