/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:48:19 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/23 17:15:36 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int unsigned	i;
	int unsigned	j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (i < nb && src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = 0;
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
	char *src = "istoa   ";
	char dest[14] = "cata-me ";

	printf("ft_strncat -> %s\n", ft_strncat(dest, src, -1));
	printf("OG strncat -> %s\n", strncat(dest, src, -1));
}*/
