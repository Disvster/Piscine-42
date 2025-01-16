void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = size - 1;
	temp = 0;
	while (i < j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}
}
/*
#include <stdio.h>
int	main()
{
	int	tab[] = {1, 2, 3, 4, 5, 6, 7};
	int	size = 7;
	int	i = 0;
	ft_rev_int_tab(tab, size);
	printf("{");
	while (size > 0)
	{
		printf("%d", tab[i]);
		if (size != 1)
			printf(", ");
		size--;
		i++;
	}
	printf("}\n");
	return 0;
}*/
