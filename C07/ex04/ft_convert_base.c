/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:51:33 by manmaria          #+#    #+#             */
/*   Updated: 2025/02/03 20:26:55 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	ft_atoi_base(char *str, char *base)
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
	return (res * sign);
}

int	len_number_to(int res_atoi, int len_base_to)
{
	int		len_nbr;
	int		res;

	res = res_atoi;
	len_nbr = 0;
	if (res < 0)
	{
		res *= -1;
		len_nbr++;
	}
	while (res >= len_base_to)
	{
		res = res / len_base_to;
		len_nbr++;
	}
	len_nbr++;
	return (len_nbr);
}

char	*ft_putnbr_base(int nb, char *base)
{
	int		i;
	int		len_nbr;
	int		len_base;
	long	nbr;
	char			*new_nbr;
	
	i = -1;
	nbr = nb;
	len_base = ft_strlen(base);
	len_nbr = len_number_to(nbr, len_base);
	new_nbr = (char *)malloc(sizeof(char) * (len_nbr + 1));
	while (i <= len_nbr) // this might not work
	{
		if (nbr < 0)
		{
			nbr *= -1;
			new_nbr[0] = '-';
			i = 1;
		}
		if (nbr >= len_base)
		{
			new_nbr[len_nbr--] = base[nbr % len_base];
			nbr /= len_base;
		}
		if (nbr < len_base)
		{
			new_nbr[i] = base[nbr];
			i++;
		}
	}
	return (new_nbr);
}
