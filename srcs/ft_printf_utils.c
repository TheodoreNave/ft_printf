/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:26:23 by tnave             #+#    #+#             */
/*   Updated: 2021/02/24 13:27:28 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	is_int(char c)
{
	return (c == 'd' || c == 'i');
}

char	is_u_int(char c)
{
	return (c == 'u');
}

char	is_ptr(char c)
{
	return (c == 'p');
}

char 	is_hex(char c)
{
	return (c == 'x' || c == 'X');
}

char	is_str(char c)
{
	return (c == 's');
}

char	is_char(char c)
{
	return (c == 'c' || c == '%');
}

char	is_width(char c)
{
	return (c == '-');
}

char	is_prec(char c)
{
	return (c == '.');
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		check_type(char c)
{
	return (c == 'c' || c == 'd' || c == 'u' || c == 'i' || c == 's' || c == 'x' || c == 'X' || c == 'p');					// Maybe only one is cool ???? lol
}

int		ft_type(char c)
{
	return (c == 'c' || c == 'd' || c == 'u' || c == 'i' || c == 's' || c == 'x' || c == 'X' || c == 'p');
}