/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:28:39 by tnave             #+#    #+#             */
/*   Updated: 2021/03/02 15:39:30 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// Need shortcut for parse and printf functions and each display (Normally)

int		ft_type(char c)
{
	return (c == 'c' || c == '%' || c == 'd' || c == 'u' 
	|| c == 'i' || c == 's' || c == 'x' || c == 'X' || c == 'p' || c == '\0');
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_pfconv	*ft_parse(t_pfconv *c_conv, const char *str, va_list iter)
{
	int i;
	
	i = 0;
	if (str[i] == '0')
	{
		c_conv->zero = 1;
		i++;
	}
	if (str[i] == '-')
	{
		c_conv->dash = 1;
		i++;
	}
	if (ft_isdigit(str[i]) || str[i] == '*')
	{
		if (str[i] == '*')
		{
			c_conv->width = va_arg(iter, int);
			i++;
		}
		else
			c_conv->width = atoi(&str[i]);				// ADD FT_ATOI
	}
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		c_conv->dot = 1;
		c_conv->prec = 0;
		i++;
		if (ft_isdigit(str[i]) || str[i] == '*')
		{
			if (str[i] == '*')
			{
				c_conv->prec = va_arg(iter, int);
				i++;
			}
			else 
				c_conv->prec = atoi(&str[i]);			// ADD FT_ATOI
		}
	}
	return (c_conv);
}

int		ft_printf(const char *str, ...)
{
	t_pfstruct pf;
	ft_memset(&pf, 0, sizeof(pf));
	va_list iter;
	t_pfconv c_conv;
	va_start(iter, str);

	if (!str)
		return (c_conv.width);
	while (str[pf.i])					
	{									
		if (str[pf.i] != '%')			  
			add_to_buff(&pf, str[pf.i]);
		if (str[pf.i] == '%')
		{
			pf.i++;
			pf.j = pf.i;
			while (!ft_type(str[pf.i]))
				pf.i++;				
			pf.type = str[pf.i];
			ft_parse(ft_reset(&c_conv), &str[pf.j], iter);
			if (is_int(pf.type))
				ft_display_int(&pf, c_conv, iter);
			if (is_u_int(pf.type))
				ft_display_u_int(&pf, c_conv, iter);
			if (is_hex(pf.type))
				ft_display_hex(&pf, c_conv, iter);
			if (is_ptr(pf.type))
				ft_display_ptr(&pf, c_conv, iter);
			if (is_str(pf.type))
				ft_display_str(&pf, c_conv, iter);
			if (is_char(pf.type))
				ft_display_char(&pf, c_conv, iter);
			if (is_mod(pf.type))
				ft_display_mod(&pf, c_conv);
		}
		pf.i++;
	}
	empty_buff(&pf);
	va_end(iter);
	return (0);										
}

// int main(void)
// {
// 	char *str = "Salut";

// 	printf("\n");
// 	printf("OG = %*s", -32, "abc");	
// 	printf("\n");											// width < prec
// 	ft_printf("DA = %*s", -32, "abc");	
// 	// printf("OG = %.0s", "theo");
// 	// printf("OG = %.s", "theo");							// width > prec
// 	// ft_printf("DA = %.0d", 0);
// }