/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:39:14 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/27 19:39:11 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	**ft_sort_params(char **argv)
{
	int		i;
	int		j;
	char	*swp;

	swp = 0;
	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				swp = argv[i];
				argv[i] = argv[j];
				argv[j] = swp;
				j = i + 1;
			}
			j++;
		}
		i++;
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	(void)argc;
	j = 1;
	i = 0;
	ft_sort_params(argv);
	while (argv[j])
	{
		while (argv[j][i])
		{
			write(1, &argv[j][i], 1);
			i++;
		}
		i = 0;
		write (1, "\n", 1);
		j++;
	}
	return (0);
}
