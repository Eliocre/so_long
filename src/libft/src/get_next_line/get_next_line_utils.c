/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:13:24 by eandre            #+#    #+#             */
/*   Updated: 2024/01/08 16:29:36 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

int	ft_newline_finder(t_listgnl *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->content[i] && i < BUFFER_SIZE)
		{
			if (lst->content[i] == '\n' || !lst->content[i])
				return (1);
			++i;
		}
		lst = lst->next;
	}
	return (0);
}

t_listgnl	*ft_lstlastgnl(t_listgnl **lst)
{
	t_listgnl	*current;

	current = *lst;
	if (current == NULL)
		return (current);
	while (current->next)
		current = current->next;
	return (current);
}

int	ft_lst_len(t_listgnl *current)
{
	int	i;
	int	k;

	k = 0;
	while (current)
	{
		i = 0;
		while (current->content[i])
		{
			if (current->content[i] == '\n')
				return (++k);
			++i;
			++k;
		}
		current = current->next;
	}
	return (k);
}

void	line_stocker(t_listgnl *current, char *line)
{
	int	j;
	int	i;

	j = 0;
	while (current)
	{
		i = 0;
		while (current->content[i])
		{
			if (current->content[i] == '\n')
			{
				line[j++] = current->content[i];
				return ;
			}
			else
				line[j++] = current->content[i++];
		}
		current = current->next;
	}
}

void	free_all(t_listgnl **lst)
{
	t_listgnl	*current;

	if (!lst)
		return ;
	while (*lst)
	{
		current = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = current;
	}
	*lst = NULL;
}
