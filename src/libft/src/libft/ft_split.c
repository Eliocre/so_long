/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:50:36 by eandre            #+#    #+#             */
/*   Updated: 2024/01/18 16:23:05 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	i;
	int	cmp;
	int	bool;

	i = 0;
	cmp = 0;
	bool = 0;
	while (s[i])
	{
		if (s[i] != c && bool == 0)
		{
			bool = 1;
			cmp++;
		}
		else if (s[i] == c && bool == 1)
			bool = 0;
		i++;
	}
	return (cmp);
}

static void	free_all(char **strs)
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

static char	*create_words(char const *s, int len, char **strs, int j)
{
	int		i;

	strs[j] = malloc((len + 1) * sizeof(char));
	if (strs[j] == NULL)
	{
		free_all(strs);
		return (NULL);
	}
	i = 0;
	while (s[i] && i < len)
	{
		strs[j][i] = s[i];
		i++;
	}
	strs[j][i] = '\0';
	return (strs[j]);
}

static char	**split_word(char **strs, char *s, char c)
{
	int		i;
	int		j;
	int		temp;

	j = 0;
	i = 0;
	temp = 0;
	while (s[i])
	{
		while (s[i] && s[i++] == c)
			temp = i;
		while (s[i] && s[i] != c)
			i++;
		if (temp != i)
		{
			if (create_words(&s[temp], i - temp, strs, j) == NULL)
				return (NULL);
			j++;
		}
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (s == NULL)
		return (0);
	strs = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	strs = split_word(strs, (char *)s, c);
	if (strs == NULL)
		return (NULL);
	strs[count_words(s, c)] = NULL;
	return (strs);
}
