/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:06:02 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/20 20:25:09 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
	if (ac != 3)
		printf("escreve duas strings oh nabo");
	else
		printf("ft_strcmp -> %d\n", ft_strcmp(av[1], av[2]));
		printf("OG strcmp -> %d\n", strcmp(av[1], av[2]));
}*/
