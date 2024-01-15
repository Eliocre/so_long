/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:20:33 by eandre            #+#    #+#             */
/*   Updated: 2024/01/08 14:14:17 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*lstreturn;
	t_list	*lsttemp;

	lstreturn = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		if (content == NULL)
		{
			ft_lstclear(&lstreturn, del);
			return (NULL);
		}
		lsttemp = ft_lstnew(content);
		if (lsttemp == NULL)
		{
			(*del)(content);
			ft_lstclear(&lstreturn, del);
			return (NULL);
		}
		ft_lstadd_back(&lstreturn, lsttemp);
		lst = lst->next;
	}
	return (lstreturn);
}
