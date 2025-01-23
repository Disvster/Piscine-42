/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:25:57 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/23 16:37:50 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
//	if (ac != 4)
//		printf("escreve bem os argumentos oh nabo(\"s1\" \"s2\" \"n\")");
//	else
//		printf("ft_strncmp -> %d\n", ft_strncmp(av[1], av[2], atoi(av[3])));
//		printf("OG strncmp -> %d\n", strncmp(av[1], av[2], atoi(av[3])));
//
	char *str1 = "Hellz";
	char *str2 = "Hello";
	printf("ft_strncmp -> %d\n", ft_strncmp(str1, str2, 4));
	printf("OG strncmp -> %d\n", strncmp(str1, str2, 4));

}*/
