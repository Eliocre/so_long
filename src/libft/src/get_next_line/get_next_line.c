/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:14:03 by eandre            #+#    #+#             */
/*   Updated: 2024/01/29 19:00:21 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*get_next_line(int fd)
{
	static t_listgnl	*lst[1024];
	char				*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (read(fd, &line, 0) < 0)
	{
		free_all(&lst[fd]);
		return (NULL);
	}
	ft_reader(&lst[fd], fd);
	if (lst[fd] == NULL)
		return (NULL);
	line = ft_line_new(&lst[fd], line);
	if (lst[fd] == NULL)
		return (NULL);
	ft_lstcleargnl(&lst[fd]);
	return (line);
}

void	ft_reader(t_listgnl **lst, int fd)
{
	int		read_value;
	char	*buffer;

	read_value = 0;
	while (ft_newline_finder(*lst) != 1)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return (free_all(lst));
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[read_value] = '\0';
		ft_addback(lst, buffer);
	}
}

void	ft_addback(t_listgnl **lst, char *buffer)
{
	t_listgnl	*new;
	t_listgnl	*last;

	if (buffer[0] == '\0')
		return (free(buffer));
	new = malloc(sizeof(t_listgnl));
	if (new == NULL)
	{
		free(buffer);
		return (free_all(lst));
	}
	last = ft_lstlastgnl(lst);
	if (last == NULL)
		*lst = new;
	else
		last->next = new;
	new->content = buffer;
	new->next = NULL;
}

char	*ft_line_new(t_listgnl **lst, char *line)
{
	t_listgnl	*current;
	int			len;

	current = *lst;
	len = ft_lst_len(current);
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
	{
		free_all(lst);
		return (NULL);
	}
	line_stocker(current, line);
	line[len] = '\0';
	return (line);
}

void	ft_lstcleargnl(t_listgnl **lst)
{
	t_listgnl	*last;
	int			i;
	int			k;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free_all(lst));
	last = ft_lstlastgnl(lst);
	i = 0;
	k = 0;
	while (last->content[i] && last->content[i] != '\n')
		++i;
	while (last->content[i] && last->content[++i])
		buffer[k++] = last->content[i];
	buffer[k] = '\0';
	free_all(lst);
	ft_addback(lst, buffer);
}
