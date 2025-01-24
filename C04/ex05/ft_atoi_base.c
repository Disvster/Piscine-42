/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:51:47 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/24 23:04:46 by manmaria         ###   ########.fr       */
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
		if ((str[i] >= 32 && str[i] <= 127) || (str[i] != '+' && str[i] != '-'))
			verify[iv]++;
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	sign;
	int	base_len;

	sign = 1;
	i = 0;
	res = 0;
	base_len = ft_strlen(base);
	if (base_len == 1 || base_len == 0 || verify_base(base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 14) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * base_len + str[i] - 48;
		i++;
	}
	return (sign * res);
}

#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		 printf("%d\n", ft_atoi_base((av[1]), av[2]));
		 printf("\n");
	}
	else{
		printf("burro da merda escreve duas strings tipo um numero e uma base\n");
	}
}
