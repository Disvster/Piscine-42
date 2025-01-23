/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:16:39 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/23 16:38:41 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (src[i])
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
	char *src = "isto";
	char dest[14] = "cata-me ";

	printf("ft_strcmp -> %s\n", ft_strcat(dest, src));
//	printf("OG strcmp -> %s\n", strcat(dest, src));
}*/
