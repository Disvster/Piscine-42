int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%d characters \n", ft_strlen(argv[1]));
}*/
