/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:25:18 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/19 02:01:35 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	*src = "se isto aparecer no terminal entao deu certo";
	char	dest[40];

	printf("ft_strcpy: \"%s\"\n", ft_strcpy(dest,src));
	printf("OG strcpy: \"%s\"\n", strcpy(dest,src));
	return 0;
}*/
