 (str[i] != '+' && str[i] != '-')/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stress_test_ft_putnbr_base.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:19:17 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/25 22:33:23 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char n)
{
	write(1, &n, 1);
}

int	verify_base(char *str)
{
	auto int i, iv;
	auto int verify[128] = {0};
	i = 0;
	while (str[i])
	{
		iv = (int)str[i];
		if (verify[iv] == 1 || (str[i] == '+' || str[i] == '-'))
			return (0);
		if ((str[i] > 32 && str[i] < 127))
			verify[iv]++;
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len_base;
	long	nb;

	nb = nbr;
	len_base = ft_strlen(base);
	if (len_base == 0 || len_base == 1 || !verify_base(base))
		return ;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= len_base)
	{
		ft_putnbr_base((nb / len_base), base);
		ft_putnbr_base((nb % len_base), base);
	}
	else
		ft_putchar(base[nb]);
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
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
        while ((bytes_read = read(fd, buf, BUFF_SIZE)) > 0)
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
                    ft_putnbr_base(atoi(num), base);
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
