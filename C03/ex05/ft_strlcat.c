/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:15:24 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/23 20:19:11 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	i;
	unsigned int	limit;

	limit = 0;
	limit = dest_len - size;
	i = 0;
	dest_len = ft_strlen(dest);
	if (!size || size <= dest_len)
		return ((dest_len) + ft_strlen(src));
	while (src[i] && i < (size - dest_len - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = 0;
	return (dest_len + ft_strlen(src));
}
/*
#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	char *src = "isto.";
	char dest[14] = "cata-me,";

	printf("a string dest antes -> %s\n", dest);
	printf("ft_strlen(dest) -> %i\n", ft_strlen(dest));
  	printf("a string src -> %s\n", src);
	printf("ft_strlen(src) -> %i\n", ft_strlen(src));
	printf("ft_strlcat -> %i\n", ft_strlcat(dest, src, atoi(av[1])));
	printf("a string dps -> %s\n", dest);
	//printf("OG strlcat -> %zu\n", strlcat(dest, src, 6));
}*/
