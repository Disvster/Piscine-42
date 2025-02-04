/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:34:30 by manmaria          #+#    #+#             */
/*   Updated: 2025/02/03 16:58:51 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	i = 0;
	*range = NULL;
	if (min >= max)
		return (0);
	*range = (int *)malloc(sizeof(int) * size);
	if (!*range)
		return (-1);
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{	// in ft_ult_rang; insid the while loop
       	// you could you could (*range)[i] instead

	int	i;
	int	**arr = (int **)malloc(sizeof(int *));
	int	size;

	(void)ac;
	i = 0;
	size = ft_ultimate_range(arr, atoi(av[1]), atoi(av[2]));
	while (i < size)
	{
		printf("%d ", arr[0][i]);
		i++;
	}
	printf("\nsize = %d\n", size);
	free (arr[0]);
	free (arr);
	return (0);
}*/
