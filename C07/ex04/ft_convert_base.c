/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:51:33 by manmaria          #+#    #+#             */
/*   Updated: 2025/01/30 23:06:20 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	verify_base(char *base);
int	ws_sign(char *str, int sign, int *p_i);
int	nbr_base(char symb, char *base);
int	ft_atoi_base(char *str, char *base, int *pnbr_sign);
void	ft_putnbr_base(int nbr, char *base, int sign, char *new_nbr);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

#include <stdio.h>

int	main(int ac, char **av)
{
	char	*str = ft_convert_base(av[1], av[2], av[3]);
	
	(void)ac;
	str = ft_convert_base(av[1], av[2], av[3]);
	printf("%s\n", str);
	free (str);
	return(0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;
	int		res_atoi;
	char	*con_bs_nbr;

	sign = 0;
	con_bs_nbr = NULL;
	if (verify_base(base_from) <= 1 || verify_base(base_to) <= 1)
		return (NULL);
	res_atoi = ft_atoi_base(nbr, base_from, &sign);
	ft_putnbr_base(res_atoi, base_to, sign, con_bs_nbr);
	return (con_bs_nbr);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	verify_base(char *base) //returns len_base(i) or 0 if invalid base
{
	int	i;
	int	c;
	int	*verify;

	i = 0;
	c = 0;
	verify = malloc(sizeof(int) * 128);
	while (c < 128)
		verify[c++] = 0;
	while (base[i])
	{
		c = (int)base[i];
		if (base[i] == ' ' || base[i] == '+' || verify[c] == 1 ||
			(base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		if (!verify[c]) //check acceptable chars
			verify[c]++;
		i++;
	}
	free (verify);
	return (i);
}

int	ws_sign(char *str, int sign, int *p_i)
{
	int	i;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*p_i = i;
	return (sign);
}

int	nbr_base(char symb, char *base)
{
	int	ib;

	ib = 0;
	while (base[ib])
	{
		if (symb == base[ib])
			return (ib);
		ib++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base, int *pnbr_sign)
{
	int	i;
	int	res;
	int	sign;
	int	id_b; // index of str[i] @ base
	
	i = 0;
	res = 0;
	sign = 1;
	sign = ws_sign(str, sign, &i); //&i to get index @ number on string
	id_b = nbr_base(str[i], base);
	while (str[i] && id_b != -1)
	{	/* variable for base length?*/

		res = (res * ft_strlen(base)) + id_b;
		i++;
		id_b = nbr_base(str[i], base); 
	}
	*pnbr_sign = sign;
	return (res * sign);
}

void	ft_putnbr_base(int nbr, char *base, int sign, char *new_nbr) //sign recebe o valor do p_i da atoi
{
	long			nb;
	int		len_base;
	char	*temp_nbr;
		
	nb = nbr;
	len_base = ft_strlen(base);
	temp_nbr = NULL;
	if (sign == -1)
	{
		temp_nbr = (char *)malloc(sizeof(char));
		*temp_nbr= '-';
		temp_nbr++;
	}
	if (nb >= len_base)
	{	
		ft_putnbr_base((nb / len_base), base, 1, new_nbr);
		ft_putnbr_base((nb % len_base), base, 1, new_nbr);
	}
	else 
	{	//iterative malloc?
		temp_nbr = (char *)malloc(sizeof(char));
		*temp_nbr = base[nb];
		temp_nbr++;
	}
	new_nbr = temp_nbr - ft_strlen(temp_nbr);
}
