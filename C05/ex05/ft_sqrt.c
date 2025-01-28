/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:01:53 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/28 22:37:29 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	n;

	n = 1;
	if (nb <= 0)
		return (0);
	while (n * n < (unsigned int)nb)
		n++;
	if (n * n == (unsigned int)nb)
		return (n);
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	(void)ac;
	printf("%d\n", ft_sqrt(atoi(av[1])));
}*/
