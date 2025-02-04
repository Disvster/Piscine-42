/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:51:33 by manmaria          #+#    #+#             */
/*   Updated: 2025/02/04 00:51:29 by disvster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	verify_base(char *base);
int	ws_sign(char *str, int sign, int *p_i); //retorna -1||1 e da i p/ft_atoi
int	nbr_base(char symb, char *base); //retorna -1(err) ou indice do symb na base
long	ft_atoi_base(char *str, char *base);
int	len_number_to(long res_atoi, int len_base_to);
char	*ft_putnbr_base(long nbr, int len_nbr, char *base, char *new_nbr);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*con_nb = NULL; //norm ^ check subject
	int		len_nbr;
	long			res_atoi;

	if (verify_base(base_from) <= 1 || verify_base(base_to) <= 1)
		return (NULL);
	res_atoi = ft_atoi_base(nbr, base_from);
	len_nbr = len_number_to(res_atoi, ft_strlen(base_to));
	con_nb = (char *)malloc(sizeof(char) * (len_nbr + 1));
	con_nb = ft_putnbr_base(res_atoi, len_nbr, base_to, con_nb);
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
