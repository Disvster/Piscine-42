/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:51:33 by manmaria          #+#    #+#             */
/*   Updated: 2025/02/04 10:42:17 by manmaria         ###   ########.fr       */
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

int	verify_base(char *base)
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
		if (base[i] == ' ' || base[i] == '+' || verify[c] == 1
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		if (!verify[c])
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

long	ft_atoi_base(char *str, char *base)
{
	long	res;
	int		i;
	int		sign;
	int		id_b;

	i = 0;
	res = 0;
	sign = 1;
	sign = ws_sign(str, sign, &i);
	id_b = nbr_base(str[i], base);
	while (str[i] && id_b != -1)
	{
		res = (res * ft_strlen(base)) + id_b;
		i++;
		id_b = nbr_base(str[i], base);
	}
	return (res * sign);
}
