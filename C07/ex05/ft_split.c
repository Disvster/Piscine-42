/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:48:20 by manmaria          #+#    #+#             */
/*   Updated: 2025/02/04 21:35:25 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char c, char *sep)
{
	int	i;
	
	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (check_sep(str[i], sep) && str[i])
			i++;
		while (!check_sep(str[i], sep) && str[i])
			i++;
		count++;
	}
	if (check_sep(str[i - 1], sep))
		count--;
	return (count);
}

int	count_letters(char *str, char *sep)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (str[i])
	{
		while (check_sep(str[i], sep) && str[i])
			i++;
		while (!check_sep(str[i], sep) && str[i])
		{
			i++;
			j++;
		}
	}
	return (j);
}

char	*ft_strdup(char *str, char *sep)
{
	int		i;
	char	*dup;
	
	dup = NULL;
	i = 0;
	dup = (char *)malloc(sizeof(char) * (count_letters(str, sep) + 1));
	if (!dup)
		return (0);
	while (!check_sep(*str, sep) && str)
	{
		dup[i] = *str;
		i++;
		str++;
	}
	*dup = 0;
	return (dup);
}

char	**ft_split(char *str, char *charset)
{
	char		**new_str;
	int	word_count;
	int	i;

	i = 0;
	new_str = NULL;
	word_count = count_words(str, charset);
	new_str = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!word_count || !new_str)
		return (NULL);
	while (*str)// str || *str
	{
		while (check_sep(*str, charset) && *str)
			str++;
		if (!check_sep(*str, charset) && *str)
		{	new_str[i] = ft_strdup(str, charset);
			i++;
		}
		str++;
	}
	new_str[word_count] = 0;
	//free(*new_str);
	return (new_str);
}

#include <stdio.h>
int	main(int ac, char **av)
{
	char	**arr;
	int	i;
	
	i = 0;
	if (ac != 3)
	{
		printf("usage error, try -> %s <string> <string_separator>\n", av[0]);
		return (1);
	}
	arr = ft_split(av[1], av[2]);
	if (!arr)
	{
		printf("error >invalid string and/or separator<\n");
		return (1);
	}
	printf("arr -> ");
	while (arr[i])
	{
		if (arr[i + 1])
			printf("\"%s\" ", arr[i]);
		else if (!arr[i + 1])
			printf("\"%s\"\n", arr[i]);
		i++;
	}
	free(arr);
	return 0;
}
