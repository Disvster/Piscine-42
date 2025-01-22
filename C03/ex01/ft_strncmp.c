#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!n)
		return (0);
	while ((s1[i] || s2[i]) && s1[i] == s2[i] && i < n -1)
		i++;
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	printf("ft %d\n", ft_strncmp("", "Hellz", 0));
	printf("og %d\n", strncmp("", "Hellz", 0));

}*/
