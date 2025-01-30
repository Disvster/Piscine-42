/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:54:08 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/29 23:30:50 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	len_arr;
	int	i;

	len_arr = max - min;
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr = (int *)malloc(sizeof(int) * len_arr);
	*range = arr;
	while (i < len_arr)
		arr[i++] = min++;
	if (i != len_arr)
		return (-1);
	return (i);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{	
	int	*arr;
	int	min = atoi(av[1]);
	int	max = atoi(av[2]);
	int	size;
	int	i = 0;
	//(void)av;
	(void)ac;
	size = ft_ultimate_range(&arr, min, max);
	printf("{ ");
	while (i < size){
		printf("%d ", arr[i]);
		i++;
	}
	printf("}\n");
	printf("size of arr =  %d\n", size);
	free (arr);
	return (0);
}*/
