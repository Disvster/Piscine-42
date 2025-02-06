/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:30:12 by manmaria          #+#    #+#             */
/*   Updated: 2025/02/06 16:22:36 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
typedef struct	s_stock_str
{
	int size;
	char *str;
	char *copy;
}		t_stock_str*/

char	*ft_strdup(char *str)
{
	int	i;
	char		*dup;

	i = 0;
	dup = NULL;
	while (str[i])
		i++;
	dup = (char *)mallco(sizeof(char) * (i + 1));
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

			   //*point	
void	set_point(t_stock_str point, char *s_av)
{
	point->size = ft_strlen(str);
	point->str = s_av;
	point->copy = ft_strdup(s_av);
}

struct	s_stock_str	*ft_str_to_tab(int ac, char **av)
{
	struct	s_stock_str	*struct_tab;
	int	i;

	i = 0;
	struct_tab = NULL;
	struct_tab = (t_stock *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!struct_tab)
		return (NULL);
	while (i < ac)
	{
		set_point(struct_tab[i], av[i]);
		i++;
	}
	struct_tab[i].size = 0;
	struct_tab[i].str = 0;
	struct_tab[i].dup = 0;
	return (struct_tab);
}
