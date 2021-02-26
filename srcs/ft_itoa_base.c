/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:20:39 by tnave             #+#    #+#             */
/*   Updated: 2021/02/24 13:27:25 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_count_nbr(long nb, long base)
{
	long int	i;
	long int	nbr;
	// long int	len_base;

	nbr = nb;
	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr >= base)
	{
		nbr = nbr / base;
		i++;
	}
	return (i + 1);
}

void	ft_putnbr_base(long nb, char *base, pfstruct *pf)
{
	if (nb >= (long)ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base, pf);
		ft_putnbr_base(nb % ft_strlen(base), base, pf);
	}
	else
		add_to_buff(pf, base[nb]);
}

// char	*ft_itoa_base(uintmax_t nbr, long base)
// {
// 	static char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
// 	unsigned int    	n;
//     int              	i;
//     int             	converted_nbr[64];
//     char            	*str;

//     if (nbr == 0)
//         return ("0");
//     i = 0;
//     n = (int)nbr;
//     while (n > 0)
//     {
//         converted_nbr[i++] = n % base;
//         n /= base;
//     }
//     if (!(str = malloc(sizeof(char) * --i)))
//         return (NULL);
//     str[i + 1] = '\0';
//     while (i >= 0)
//         str[n++] = hex[converted_nbr[i--]];
//     return (str);
// }