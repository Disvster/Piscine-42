/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:41:11 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/22 11:33:29 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_symb(char c)
{
	if ((c >= 7 && c <= 13) || c == 32 
		|| (c >= 33 && c <= 47) || (c >= 58 && c <= 64)
		|| (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
		return (1);
	else
		return (0);
}

int	ft_islow(char a)
{
	if (a >= 'a' && a <= 'z')
		return (1);
	else
		return (0);
}

int	ft_iscap(char a)
{
	if (a >= 'A' && a <= 'Z')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_islow(str[0]) || (ft_symb(str[i - 1]) && ft_islow(str[i])))
			str[i] -= 32;
		else if (ft_iscap(str[i]) && (ft_islow(str[i - 1]) || ft_iscap(str[i - 1])
				|| (str[i - 1] >= '0' && str[i - 1] <= '9')))
			str[i] += 32;
		else
			i++;
	}
	return (str);
}

/*
#include <stdio.h>
int	main(int ac, char **av)
{
	if(ac == 2)
		printf("%s\n", ft_strcapitalize(av[1]));
	else
		printf("error\n");
	return (0);
}*/
