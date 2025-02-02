/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:39:28 by manmaria          #+#    #+#             */
/*   Updated: 2025/02/02 15:17:17 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	int	str_len;
	
	i = 0;
	str_len = ft_strlen(src);
	while (src[i])
	{
		*dest = src[i];
		i++;
		dest++;
	}
	*dest = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{	
	char	*f_str;	
	int		i;
	int		sep_nb;
	int		size_total;
	
	i = 0;
	sep_nb = ft_strlen(sep) * (size - 1);
	f_str = (char *)malloc(sizeof(char) * (size + sep_nb + 1));
	if (!f_str)
	{
		f_str = NULL;
		return (f_str);
	}
	while (strs[i]){// seg fault prob here
		size_total = ft_strlen(strs[i]) + ft_strlen(sep);
		i++;
	}
	while (size_total--)
	{
		f_str = ft_strcpy(f_str, strs[i]);
		if (size_total > 1)
			f_str = ft_strcpy(f_str, sep);
		i++;
	}
	*f_str = 0;
	return (f_str - ft_strlen(f_str));
}

#include <stdio.h>
int	main(void)
{
	char	*strs[] = {"ola", "malucos", "ta", "tudo"};
	char	*sep;
	char	*f_str;
	sep = " .sep. ";

	f_str = ft_strjoin(4, strs, sep);
	printf("final string -> %s\n", f_str);
	free(f_str);
}
