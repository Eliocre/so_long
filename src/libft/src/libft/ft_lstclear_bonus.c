/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:08:06 by eandre            #+#    #+#             */
/*   Updated: 2024/01/22 15:42:58 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*prev;

	prev = *lst;
	if (!(*lst))
		return ;
	while (*lst)
	{
		prev = *lst;
		*lst = (*lst)->next;
		(*del)((prev)->content);
		free(prev);
	}
	*lst = NULL;
}
