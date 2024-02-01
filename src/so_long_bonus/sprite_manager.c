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

#include "../../include/so_long_bonus.h"

t_list	*generate_animright(t_game *game, int i)
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
		tmp = ft_strjoin("textures/player/animright/right/tile", nb);
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

t_list	*generate_animdown(t_game *game, int i)
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
		tmp = ft_strjoin("textures/player/animdown/down/tile", nb);
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

t_list	*generate_animup(t_game *game, int i)
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
		tmp = ft_strjoin("textures/player/animup/up/tile", nb);
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

t_list	*generate_animleft(t_game *game, int i)
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
		tmp = ft_strjoin("textures/player/animleft/left/tile", nb);
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
