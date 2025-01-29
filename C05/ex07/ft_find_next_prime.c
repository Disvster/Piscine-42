/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:31:41 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/29 17:59:09 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	n;

	n = 2;
	if (nb < 2)
		return (0);
	while (n <= (nb / 2))
	{
		if (!(nb % n))
			return (0);
		n++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	n;

	n = nb;
	if (n <= 1)
		return (2);
	while (!ft_is_prime(n))
		n++;
	return (n);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	(void)ac;
	printf("%d\n", ft_is_prime(atoi(av[1])));
	printf("%d\n", ft_find_next_prime(atoi(av[1])));
}*/
