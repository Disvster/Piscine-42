/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:11:17 by manmaria          #+#    #+#             */
/*   Updated: 2025/02/04 17:02:46 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//      word sep is ' ' & '\t'

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
		while (str[i] != ' ' && str[i] != '\t' && str[i])
			i++;
		count++;
	}
	if (str[i - 1] == ' ' || str[i - 1] == '\t')
		count--;
	return (count);
}

#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	printf("number of words -> %d\n", count_words(av[1]));
	return 0;
}
