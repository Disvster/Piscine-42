/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:39:28 by manmaria          #+#    #+#             */
/*   Updated: 2025/02/03 15:36:30 by manmaria         ###   ########.fr       */
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

	i = 0;
	while (src[i])
	{
		*dest = src[i];
		i++;
		dest++;
	}
	*dest = 0;
	return (dest);
}

int	ft_arr_to_strlen(int len_sep, int arr_size, char **arr)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = len_sep * (arr_size - 1);
	while (i < arr_size)
	{
		total_len += ft_strlen(arr[i]);
		i++;
	}
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*f_str;
	int		i;
	int		total_len;

	if (!size)
	{
		f_str = (char *)malloc(sizeof(char));
		*f_str = 0;
		return (f_str);
	}
	total_len = ft_arr_to_strlen(ft_strlen(sep), size, strs);
	f_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!f_str)
		return (0);
	i = 0;
	while (i < size)
	{
		f_str = ft_strcpy(f_str, strs[i]);
		if (i < size - 1)
			f_str = ft_strcpy(f_str, sep);
		i++;
	}
	*f_str = 0;
	return (f_str - total_len);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*strs[] = {"ola", "malucos", "ta", "tudo"};
	char	*sep;
	char	*f_str;

	sep = " .sep. ";

	f_str = ft_strjoin(0, strs, sep);
	printf("final string -> %s\n", f_str);
	printf("strlen (f_str) -> %d\n", ft_strlen(f_str));
	free(f_str);
}*/
