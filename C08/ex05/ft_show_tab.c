/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:46:04 by manmaria          #+#    #+#             */
/*   Updated: 2025/02/06 18:10:11 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_show_tab(struct s_stock_str *p)
{
	int	i;

	i = 0;
	while (p[i].str != 0)
	{
		ft_putstr(p[i].str);
		ft_putchar('\n');
		ft_putnbr(p[i].size);
		ft_putchar('\n');
		ft_putstr(p[i].copy);
		ft_putchar('\n');
		i++;
	}
}
/*
int	main(int ac, char **av)
{
	ft_show_tab(ft_strs_to_tab(ac, av));
	free();
	return (0);
}*/
