
#include <stdio.h>
#include "ft_point.h"

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}
int	main(void)
{
	t_point point;
	
	point.x = -1000;
	point.y = 0;
	printf("before:\nx -> %d\ny -> %d\n", point.x, point.y);
	set_point(&point);
	printf("after:\nx -> %d\ny -> %d\n", point.x, point.y);
	return (0);
}
