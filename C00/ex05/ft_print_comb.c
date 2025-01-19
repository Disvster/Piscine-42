/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:25:51 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/19 22:25:57 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char x, char y, char z)
{
	write(1, &x, 1);
	write(1, &y, 1);
	write(1, &z, 1);
}

void	comma_space(void)
{
	write(1, ", ", 2);
}

void	logic(char x, char y, char z)
{
	while (x <= '7')
	{
		y = x + 1;
		while (y <= '8')
		{
			z = y + 1;
			while (z <= '9')
			{
				ft_putchar(x, y, z);
				if (x != '7')
					comma_space();
				z++;
			}
			y++;
		}
		x++;
	}
}

void	ft_print_comb(void)
{
	char	x;
	char	y;
	char	z;

	x = '0';
	y = x + 1;
	z = y + 1;
	logic(x, y, z);
}
