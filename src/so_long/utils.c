/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:42:59 by eandre            #+#    #+#             */
/*   Updated: 2024/01/15 18:19:35 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_win	new_wind(int w, int h, char *str)
{
	void	*mlx;

	mlx = mlx_init();
	return ((t_win){mlx, mlx_new_window(mlx, w, h, str), w, h});
}

int	charcmp(char *str, char c)
{
	int	i;
	int	inturn;

	i = 0;
	inturn = 0;
	while (str[i])
	{
		if (str[i] == c)
			inturn++;
		i++;
	}
	return (inturn);
}
