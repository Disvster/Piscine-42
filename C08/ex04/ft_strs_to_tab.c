/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:30:12 by manmaria          #+#    #+#             */
/*   Updated: 2025/02/06 18:09:33 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	i = ft_strlen(str);
	dup = NULL;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (0);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

void	set_point(t_stock_str *point, char *s_av)
{
	point->size = ft_strlen(s_av);
	point->str = s_av;
	point->copy = ft_strdup(s_av);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*struct_tab;
	int			i;

	i = 0;
	struct_tab = NULL;
	struct_tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!struct_tab)
		return (NULL);
	while (i < ac)
	{
		set_point(&struct_tab[i], av[i]);
		if (!struct_tab[i].copy)
		{
			while (i > 0)
				free(struct_tab[--i].copy);
			free(struct_tab);
			return (NULL);
		}
		i++;
	}
	struct_tab[i].size = 0;
	struct_tab[i].str = 0;
	struct_tab[i].copy = 0;
	return (struct_tab);
}
