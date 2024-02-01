/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_wall_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:46:05 by eandre            #+#    #+#             */
/*   Updated: 2024/02/01 18:03:31 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

t_list	*generate_animrightwall(t_game *game, int i)
{
	t_list	*anim;
	int		j;
	char	*tmp;
	char	*str;
	char	*nb;

	j = 0;
	anim = NULL;
	while (++j < 17)
	{
		nb = ft_itoa(j);
		exit_hook_without_anim(game, nb, NULL);
		tmp = ft_strjoin("textures/player/animright/rightwall/tile", nb);
		exit_hook_without_anim(game, tmp, nb);
		free(nb);
		str = ft_strjoin(tmp, ".xpm");
		exit_hook_without_anim(game, str, tmp);
		free(tmp);
		ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(game->win.mlx,
					str, &i, &i)));
		free(str);
	}
	return (anim);
}

t_list	*generate_animdownwall(t_game *game, int i)
{
	t_list	*anim;
	int		j;
	char	*tmp;
	char	*str;
	char	*nb;

	j = 0;
	anim = NULL;
	while (++j < 17)
	{
		nb = ft_itoa(j);
		exit_hook_without_anim(game, nb, NULL);
		tmp = ft_strjoin("textures/player/animdown/downwall/tile", nb);
		exit_hook_without_anim(game, tmp, nb);
		free(nb);
		str = ft_strjoin(tmp, ".xpm");
		exit_hook_without_anim(game, str, tmp);
		free(tmp);
		ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(game->win.mlx,
					str, &i, &i)));
		free(str);
	}
	return (anim);
}

t_list	*generate_animupwall(t_game *game, int i)
{
	t_list	*anim;
	int		j;
	char	*tmp;
	char	*str;
	char	*nb;

	j = 0;
	anim = NULL;
	while (++j < 17)
	{
		nb = ft_itoa(j);
		exit_hook_without_anim(game, nb, NULL);
		tmp = ft_strjoin("textures/player/animup/upwall/tile", nb);
		exit_hook_without_anim(game, tmp, nb);
		free(nb);
		str = ft_strjoin(tmp, ".xpm");
		exit_hook_without_anim(game, str, tmp);
		free(tmp);
		ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(game->win.mlx,
					str, &i, &i)));
		free(str);
	}
	return (anim);
}

t_list	*generate_animleftwall(t_game *game, int i)
{
	t_list	*anim;
	int		j;
	char	*tmp;
	char	*str;
	char	*nb;

	j = 0;
	anim = NULL;
	while (++j < 17)
	{
		nb = ft_itoa(j);
		exit_hook_without_anim(game, nb, NULL);
		tmp = ft_strjoin("textures/player/animleft/leftwall/tile", nb);
		exit_hook_without_anim(game, tmp, nb);
		free(nb);
		str = ft_strjoin(tmp, ".xpm");
		exit_hook_without_anim(game, str, tmp);
		free(tmp);
		ft_lstadd_back(&anim, ft_lstnew(mlx_xpm_file_to_image(game->win.mlx,
					str, &i, &i)));
		free(str);
	}
	return (anim);
}
