/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:18:25 by eandre            #+#    #+#             */
/*   Updated: 2024/01/15 18:48:43 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../libft/include/get_next_line.h"

t_maplayout	layout_init(void)
{
	t_maplayout	layout;

	layout.lincmp = 0;
	layout.colcmp = 0;
	layout.exicmp = 0;
	layout.stacmp = 0;
	layout.itecmp = 0;
	return (layout);
}

//check error :
//-check arg :
//--check nb arg
//--check fd
//--check map format
//-check map :
//--check rect / null map
//--check valid char
//--check nb player / end / items
//--
//game

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

void	layout_errors(t_maplayout *layout, char *map)
{
	if (layout->exicmp > 1 || layout->exicmp == 0)
	{
		ft_printf("Error \nMap needs one exit!\n");
		free(map);
		exit(1);
	}
	if (layout->stacmp > 1 || layout->stacmp == 0)
	{
		ft_printf("Error \nMap needs one start!\n");
		free(map);
		exit(1);
	}
	if (layout->itecmp == 0)
	{
		ft_printf("Error \nMap needs at least one item!\n");
		free(map);
		exit(1);
	}
}

void	free_exit(void *ptr, char *str, char *map)
{
	if (map == NULL)
	{
		ft_printf("%s", str);
		free(ptr);
		exit(1);
	}
	else
	{
		ft_printf("%s", str);
		free(ptr);
		free(map);
		exit(1);
	}
}

void	checklayout(t_maplayout *layout, char *gnl, int first_last, char **map)
{
	int	i;

	if (layout->colcmp == 0)
		layout->colcmp = ft_strlen(gnl) - 1;
	if (layout->colcmp != ft_strlen(gnl) - 1)
		free_exit(gnl, "Error \nMap is not rectangular!\n", *map);
	if ((gnl[0] != '1' || gnl[layout->colcmp - 1] != '1')
		|| (charcmp(gnl, '1') != (int)layout->colcmp
			&& first_last == 1))
		free_exit(gnl, "Error \nMap is not surrounded by walls!\n", *map);
	layout->exicmp += charcmp(gnl, 'E');
	layout->stacmp += charcmp(gnl, 'P');
	layout->itecmp += charcmp(gnl, 'C');
	i = 0;
	while (gnl[i])
	{
		if (ft_strchr("01PECM\n", gnl[i]) == NULL)
			free_exit(gnl, "Error \nMap is using invalid characters!\n", *map);
		i++;
	}
}

void	checkmap(int fd, t_maplayout *layout, char **map)
{
	char	*gnl;
	char	*lastgnl;

	lastgnl = NULL;
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
		{
			if (lastgnl == NULL)
			{
				ft_printf("Error \nMap is empty!\n");
				exit(1);
			}
			checklayout(layout, lastgnl, 1, map);
			free(lastgnl);
			return ;
		}
		free(lastgnl);
		lastgnl = ft_strdup(gnl);
		*map = ft_strjoin(*map, gnl);
		checklayout(layout, lastgnl, layout->colcmp == 0, map);
		layout->lincmp++;
	}
}

void	checkerror(int argc, char *argv, char **map)
{
	int				fd;
	char			*check;
	t_maplayout		layout;

	if (argc != 2)
	{
		ft_printf("Error \nNumber of argument is not 1!\n");
		exit(1);
	}
	check = ft_strnstr(argv, ".ber", ft_strlen(argv));
	if (check == NULL || ft_strncmp(".ber", check, 5) != 0)
	{
		ft_printf("Error \nMap is not a .ber format!\n");
		exit(1);
	}
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error \nFile descriptor is not valid!\n");
		exit(1);
	}
	layout = layout_init();
	checkmap(fd, &layout, map);
	layout_errors(&layout, *map);
}
