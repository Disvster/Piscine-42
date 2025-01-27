/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:19:17 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/27 14:16:24 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char n)
{
	write(1, &n, 1);
}

int	verify_base(char *str)
{
	auto int i, iv;
	auto int verify[128] = {0};
	i = 0;
	while (str[i])
	{
		iv = (int)str[i];
		if (verify[iv] == 1 || str[i] == '+' || str[i] == '-' 
				|| str[i] == ' ' || str[i] == 127)
			return (0);
		if (str[i] > 32 && str[i] < 127)
			verify[iv]++;
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		len_base;

	nb = nbr;
	len_base = ft_strlen(base);
	if (len_base == 0 || len_base == 1 || !verify_base(base))
		return ;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= len_base)
	{
		ft_putnbr_base((nb / len_base), base);
		ft_putnbr_base((nb % len_base), base);
	}
	else
		ft_putchar(base[nb]);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		 ft_putnbr_base(atoi(av[1]), av[2]);
		 ft_putchar('\n');
	}
	else{
		printf("escreve duas strings, um numero e uma base\n");
	}
}*/
