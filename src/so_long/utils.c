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

t_list	*ft_lstget(t_list *lst, int index)
{
	t_list	*n;
	int		i;

	i = 0;
	n = lst;
	if (n == NULL)
		return (NULL);
	if (n->next == NULL)
		return (n);
	while (n != NULL)
	{
		if (i >= index)
			return (n);
		n = n->next;
		i++;
	}
	return (NULL);
}

void	ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void * ptr)
{
	t_list	*temp;

	temp = lst;
	while (temp != NULL)
	{
		f(temp->content, ptr);
		temp = temp->next;
	}
}

void	free_map(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
