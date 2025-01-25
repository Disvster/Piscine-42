/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:51:47 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/25 18:41:22 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	verify_base(char *str)
{
	auto int i, iv;
	auto int verify[128] = {0};
	i = 0;
	while (str[i])
	{
		iv = (int)str[i];
		if (verify[iv] == 1)
			return (0);
		if ((str[i] > 32 && str[i] < 127) || (str[i] != '+' && str[i] != '-'))
			verify[iv]++;
		i++;
	}
	return (1);
}

int	nb_base(char base_char, char *base)
{
	int	ib;

	ib = 0;
	while (base[ib])
	{
		if (base_char == base[ib])
			return (ib);
		ib++;
	}
	return (-1);
}

int	negative(char *str, int *ptr_i)
{
	int	ni;
	int	sign;

	ni = 0;
	sign = 1;
	while ((str[ni] >= 9 && str[ni] <= 14) || str[ni] == 32)
		ni++;
	while (str[ni] == '+' || str[ni] == '-')
	{
		if (str[ni] == '-')
			sign *= -1;
		ni++;
	}
	*ptr_i = ni;
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	sign;
	int	base_len;
	int	ib2;

	sign = 1;
	i = 0;
	res = 0;
	base_len = ft_strlen(base);
	if (base_len == 1 || base_len == 0 || !verify_base(base))
		return (0);
	sign = negative(str, &i);
	ib2 = nb_base(str[i], base);
	while (str[i] && ib2 != -1)
	{
		res = (res * base_len) + ib2;
		i++;
		ib2 = nb_base(str[i], base);
	}
	return (res * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		 printf("%d\n", ft_atoi_base((av[1]), av[2]));
	}
	else{
		printf("escreve duas strings, um numero e uma base\n");
	}
}*/
