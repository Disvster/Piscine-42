/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:34:32 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/20 01:49:43 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_islow(char a)
{
	if ((a >= 'a' && a <= 'z'))
		return (1);
	if ((a >= 'A' && a <= 'Z'))
		return (2);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	caps;

	caps = 0;
	i = 0;
	while (str[i] != 0)
	{
		if ((!ft_symb(str[i - 1])
				&& ft_islow(str[i]) == 1) || ft_islow(str[0]) == 1)
		{
			str[i] -= 32;
			caps = 1;
		}
		else if (caps && ft_islow(str[i]) == 2)
		{
			str[i] += 32;
			caps = 1;
		}
		else
			caps = 1;
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
