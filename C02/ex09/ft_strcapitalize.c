int	ft_symb(char c)
{
	int	b;
	
	if ((c >= 7 && c <= 13) || c == 32)
		b = 0;
	else if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64))
		b = 0;
	else if ((c >= 91 && c <= 96) || (c >= 123 && c <= 126))
		b = 0;
	else
		b = 1;
	return (b);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	cap;
	
	cap = 1;
	i = 0;
	while (str[i])
	{// primeira letra da string nao da cap se estiver no inicio e nao tiver nada a tras, talvez se inverter o if / else ja da
		if (cap && !ft_symb(str[i - 1]) && (str[i] >= 97 && str[i] <= 122))
		{
			str[i] -=32;
			cap = 0;
		}
		else
			cap = 1;
		i++;
	}
	return (str);
}

#include <stdio.h>
int	main(int ac, char **av)
{
	if(ac == 2)
		printf("%s\n", ft_strcapitalize(av[1]));
	else
		printf("error\n");
	return (0);
}
