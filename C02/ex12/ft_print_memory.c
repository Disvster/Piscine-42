/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:34:24 by manmaria          #+#    #+#             */
/*   Updated: 2025/02/03 20:15:57 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char h);

void	ft_hexa_address(unsigned long long addr);

void	ft_print_spaces(int n_spaces);

void	ft_bones(unsigned char *str, unsigned int size);

void	*ft_print_memory(void *addr, unsigned int size);

void	ft_putchar(char h)
{
	write(1, &h, 1);
}

void	ft_hexa_address(unsigned long long addr)
{
	if (addr > 16)
	{
		ft_hexa_address(addr / 16);
		ft_hexa_address(addr % 16); 
	}
	else
		ft_putchar("0123456789abcdef"[addr]);
}

void	ft_print_spaces(int n_spaces)
{
	while (n_spaces--)
		ft_putchar(' ');
}

void	ft_bones(unsigned char *str, unsigned int size)
{
	unsigned int	i;
	unsigned int	c_sxt;

	i = 0;
	c_sxt = 0;
	while (i < size)
	{
		if (c_sxt == 0)
		{
			ft_hexa_address((unsigned long long)&str[i]);
			ft_putchar(':');
		}
		while (c_sxt < 16)
		{
			if (!(c_sxt % 2))
				ft_print_spaces(1);
			if (str[i + c_sxt])
			{
				ft_putchar("0123456789abcdef"[str[i + c_sxt] / 16]);
				ft_putchar("0123456789abcdef"[str[i + c_sxt] % 16]);
			}
			else
				ft_print_spaces(2);
			c_sxt++;
		}
		ft_print_spaces(1);
		while (str[i] && c_sxt > 0)
		{
			if (str[i] < 32 || str[i] > 126)
				ft_putchar('.');
			else
				ft_putchar(str[i]);
			i++;
			c_sxt--;
		}
		ft_putchar('\n');
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	ft_bones((unsigned char *)addr, size);
	return (addr);
}

int	main(void) 
{
	char	*str = "Bonjour les aminches\t\n\tc. est fou\btout\bce qu on peut faire avec\n\n\nprint_memory\t\n..lol\tlol\n \t";
	int	size = 89;
	ft_print_memory(str, size);
}
