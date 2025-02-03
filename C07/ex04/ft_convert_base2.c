/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:51:33 by manmaria          #+#    #+#             */
/*   Updated: 2025/02/03 19:48:12 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	verify_base(char *base);
int	ws_sign(char *str, int sign, int *p_i); //retorna -1||1 e da i p/ft_atoi
int	nbr_base(char symb, char *base); //retorna -1(err) ou indice do symb na base
int	ft_atoi_base(char *str, char *base);
int	len_number_to(int res_atoi, int len_base_to);
char	*ft_putnbr_base(int nb, char *base_);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*con_nb;

	con_nb = ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to);
	if (verify_base(base_from) <= 1 || verify_base(base_to) <= 1)
		return (NULL);
	return (con_nb);
}

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

/*char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
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
}*/

/*
*/
