/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:16:31 by manmaria          #+#    #+#             */
/*   Updated: 2025/02/06 12:22:16 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "ft_point.h"
void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}
int	main(void)
{
	t_point	point;
	set_point(&point);
	printf("x -> %d\ny -> %d\n", point.x, point.y);
	return (0);
}
