/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:15:07 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/23 16:39:08 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	h;

	h = 0;
	i = 0;
	if (!*to_find)
		return (str);
	while (str[i])
	{
		while (str[i + h] == to_find[h] && str[i + h] && to_find[h])
		{
			if (!to_find[h + 1])
				return (&str[i]);
			h++;
		}
		h = 0;
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
	if (ac != 3)
		printf("escreve duas strings oh nabo");
	else{
		printf("ft_strstr -> %s\n", ft_strstr(av[1], av[2]));
		printf("OG strstr -> %s\n", strstr(av[1], av[2]));
	}
}*/
