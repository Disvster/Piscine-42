/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_ft_atoi_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:51:47 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/27 13:48:12 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	verify_base(char *str)
{
	auto int i, iv;
	auto int verify[128] = {0};
	i = 0;
	while (str[i])
	{
		iv = (int)str[i];
		if (verify[iv] == 1 || str[i] == '+' || str[i] == '-')
			return (0);
		if ((str[i] > 32 && str[i] < 127))
			verify[iv]++;
		i++;
	}
	return (1);
}

int	nb_base(char base_char, char *base)
{
	int	ib;

	ib = 0;
	while (base[ib])
	{
		if (base_char == base[ib])
			return (ib);
		ib++;
	}
	return (-1);
}

int	negative(char *str, int *ptr_i)
{
	int	ni;
	int	sign;

	ni = 0;
	sign = 1;
	while ((str[ni] >= 9 && str[ni] <= 14) || str[ni] == 32)
		ni++;
	while (str[ni] == '+' || str[ni] == '-')
	{
		if (str[ni] == '-')
			sign *= -1;
		ni++;
	}
	*ptr_i = ni;
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	sign;
	int	base_len;
	int	ib2;

	sign = 1;
	i = 0;
	res = 0;
	base_len = ft_strlen(base);
	if (base_len == 1 || base_len == 0 || !verify_base(base))
		return (0);
	sign = negative(str, &i);
	ib2 = nb_base(str[i], base);
	while (str[i] && ib2 != -1)
	{
		res = (res * base_len) + ib2;
		i++;
		ib2 = nb_base(str[i], base);
	}
	return (res * sign);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 1024
// Macros for ANSI color codes
#define RESET_COLOR "\033[0m"
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define MAGENTA_TEXT "\033[35m"
#define CYAN_TEXT "\033[36m"
#define WHITE_TEXT "\033[37m"
#include <fcntl.h>


int main(int ac, char **av)
{
    if (ac < 2)
    {
        printf("Usage: %s <file1> [file2 ...]\n", av[0]);
        return (1);
    }

    for (int i = 1; i < ac; i++)
    {
        int fd = open(av[i], O_RDONLY);
        if (fd < 0)
        {
            perror("Error opening file");
            continue;
        }

        char buf[BUFF_SIZE + 1]; 
        ssize_t bytes_read;
        while ((bytes_read = readf(fd, buf, BUFF_SIZE)) > 0)
        {
            buf[bytes_read] = '\0'; 
            char *line = strtok(buf, "\n");
            while (line != NULL)
            {
                char num[12] = {0}; 
                char base[100] = {0};

                if (sscanf(line, "%11s %99s", num, base) == 2) 
                {
                    printf("\t-> num:"RED_TEXT "%s\t" RESET_COLOR " base:" BLUE_TEXT "%s" RESET_COLOR, num, base);
                    ft_atoi_base(num, base);
                    printf("\n");
                }
                else
                {
                    printf(RED_TEXT "Invalid line format: %s\n" RESET_COLOR, line);
                }

                line = strtok(NULL, "\n");
            }
        }

        if (bytes_read < 0)
            perror("Error reading file");

        close(fd);
    }

    return (0);
}
