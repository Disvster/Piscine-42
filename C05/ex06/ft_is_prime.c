/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:26:19 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/29 17:30:41 by manmaria         ###   ########.fr       */
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
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	(void)ac;
	printf("%d\n", ft_is_prime(atoi(av[1])));
}

// vou dividir o numero (nb) por 2:
//  - ou ate ele ser divisivel por o resultado da div de nb por 2; return (0)
//  - ou ser divisivel por outro numero antes; return (0)
//  - ou nao ser divisivel por nenhum numero senao ele proprio ou 1.
// os primes sao so diviseis por 1 ou ele proprios.
// quando (n > (nb / 2)), entao encontramos 
// um numero primo pq nao e divisiel por 2, nem pela metade dele(valor max),
// nem por nada no meio.
{
	unsigned int	n;

	n = 2;
	if (nb < 2)
		return (0);
	while ((unsigned)nb % n != 0)
		n++;
	if ((unsigned)nb == n)
		return (1);
	return (0);
}*/
