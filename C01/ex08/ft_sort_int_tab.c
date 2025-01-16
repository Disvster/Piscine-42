void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 1;
	temp = 0;
	while (i < (size - 1))
	{
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
				j = i + 1;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}
/*
#include <stdio.h>
int	main()
{
	int	tab[] = {4, 5, 7, 3, 2, -6, -1};
	int	size = 7;
	int	i = 0;
	
	ft_sort_int_tab(tab, size);
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
