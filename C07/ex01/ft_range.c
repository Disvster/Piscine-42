/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:56:05 by manmaria          #+#    #+#             */
/*   Updated: 2025/02/03 16:20:29 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	len_arr;
	int	i;

	i = 0;
	arr = NULL;
	len_arr = max - min;
	if (min >= max)
		return (arr);
	arr = (int *)malloc(sizeof(int) * len_arr);
	while (len_arr--)
		arr[i++] = min++;
	return (arr);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{	
	int	*arr;
	int	min = atoi(av[1]);
	int	max = atoi(av[2]);

	(void)ac;
	arr = ft_range(min, max);
	printf("{ ");
	for (int i = 0; i < (max - min); i++)
		printf("%d ", arr[i]);
	printf("}\n");
	free (arr);
	return (0);
}*/
