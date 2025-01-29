/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_ft_ultimate_range.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:34:30 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/29 23:32:07 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// faz isto sem criar *arr, faz malloc de *range; while *range[i++] = min++; 
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*arr;
	int	size;

	size = max - min;
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr = (int *)malloc(sizeof(int) * size);
	*range = arr;
	while (i < size)
	{
		arr[i] = min;
		min++;
		i++;
	}
	if (i != size)
		return (-1);
	return (size);
}

#include <stdio.h>
int	main()
{
	int	i;
	int	*arr;
	int	size;

	i = 0;
	size = ft_ultimate_range(&arr, 2, 5);
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\nsize = %d\n", size);
//	free (arr);
	return (0);
}
