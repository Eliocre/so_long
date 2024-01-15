/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:14:25 by eandre            #+#    #+#             */
/*   Updated: 2024/01/15 15:40:12 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_listgnl
{
	char				*content;
	struct s_listgnl	*next;
}					t_listgnl;

char		*get_next_line(int fd);
void		ft_addback(t_listgnl **lst, char *buffer);
char		*ft_line_new(t_listgnl **lst, char *line);
void		ft_lstcleargnl(t_listgnl **lst);
void		ft_reader(t_listgnl **lst, int fd);
t_listgnl	*ft_lstlastgnl(t_listgnl **lst);
int			ft_newline_finder(t_listgnl *lst);
int			ft_lst_len(t_listgnl *current);
void		line_stocker(t_listgnl *current, char *line);
void		free_all(t_listgnl **lst);

#endif
