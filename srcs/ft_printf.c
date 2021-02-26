/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:28:39 by tnave             #+#    #+#             */
/*   Updated: 2021/02/24 15:13:50 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void	add_to_buff(pfstruct *pf, char c)
{
	pf->buf[pf->x] = c;
	pf->x++;
	if (pf->x == BUFF_MAX)
		empty_buff(pf);
}

pfconv	*ft_reset(pfconv *c_conv)
{
	c_conv->width = 0;	// Largeur after 0 or -
	c_conv->prec = -1;	// Nb prec
	c_conv->dot = 0; 	// 
	c_conv->conv = 0; 	// 
	c_conv->zero = 0;	// 0 or not
	c_conv->dash = 0;	// Dash or not
	return (c_conv);
}


void	empty_buff(pfstruct *pf)
{
	write(1, &pf->buf, pf->x);
	pf->x = 0;
}


pfconv	*ft_parse(pfconv *c_conv, const char *str, va_list iter)
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
			// write(1, "a\n", 2);
		}
		else
			c_conv->width = atoi(&str[i]);
	}
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		c_conv->dot = 1;
		i++;
		if (ft_isdigit(str[i]) || str[i] == '*')
		{
			if (str[i] == '*')
			{
				c_conv->prec = va_arg(iter, int);
				i++;
			}
			else 
				c_conv->prec = atoi(&str[i]);
		}
	}
	return (c_conv);
}

int		ft_printf(const char *str, ...)
{

	pfstruct pf;
	memset(&pf, 0, sizeof(pf));		// To ft_memset
	va_list iter;
	pfconv c_conv;
	va_start(iter, str);

	if (!str)
		return (0);
	while (str[pf.i])					
	{									
		if (str[pf.i] != '%')			  
			add_to_buff(&pf, str[pf.i]);
		if (str[pf.i] == '%')
		{
				pf.i++;
				if (!ft_type(pf.i))
					pf.j = pf.i;
				while (!check_type(str[pf.i]))
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
		}
		pf.i++;
	}
	empty_buff(&pf);
	va_end(iter);
	return (0);												
}

// int main(void)
// {
// 	// pfconv	c_conv;
	
// 	printf("\n");
// 	printf("OG PRINTF = %*d", 34, 2);							// width > prec
// 	printf("\n");											// width < prec
// 	ft_printf("DA PRINTF = %*d", 34, 2);
// 														// If width is - cancel the prec
// 														// If there is a number just after the %, check directly the flag
// // // 	// printf("[%d]\n", c_conv.width);
// // // 	// printf("[%d]\n", c_conv.dot);
// // // 	// printf("[%d]\n", c_conv.prec);
// // // 	// printf("[%d]\n", c_conv.dash);
// // // 	// printf("\n");
// // // 	// printf("======MON_PRINTF_PTR=====\n");
// // // 	// ft_printf("%p", &p);
// // // 	// printf("\n");
// // // 	// printf("======OG_PRINTF_PTR=====\n");
// // //  	// printf("%p", &p);
// // //  	// printf("\n");

	 
// // // 	// printf("======MON_PRINTF_CHAR=====\n");
// // // 	// ft_printf("%c", c);
// // // 	// printf("\n");
// // // 	// printf("======OG_PRINTF_CHAR=====\n");
// // //  	// printf("%c", c);
// // //  	// printf("\n");


// // // 	// printf("======MON_PRINTF_INT_D=====\n");
// // // 	// ft_printf("%d", d);
// // // 	// printf("\n");
// // // 	// printf("======OG_PRINTF_INT_D=====\n");
// // //  	// printf("%d", d);
// // //  	// printf("\n");

	 
// // // 	// printf("======MON_PRINTF_INT_I=====\n");
// // // 	// ft_printf("%i", d);
// // // 	// printf("\n");
// // // 	// printf("======OG_PRINTF_INT_I=====\n");
// // //  	// printf("%i", d);
// // //  	// printf("\n");

	 
// // // 	// printf("======MON_PRINTF_U_INT=====\n");					// NOT WORKING
// // // 	// ft_printf("%u", d);
// // // 	// printf("\n");
// // // 	// printf("======OG_PRINTF_U_INT=====\n");
// // //  	// printf("%u", d);
// // //  	// printf("\n");

	 
// // // 	// printf("======MON_PRINTF_HEX=====\n");						// NOT WORKING
// // // 	// ft_printf("%x", d);
// // // 	// printf("\n");
// // // 	// printf("======OG_PRINTF_HEX=====\n");
// // //  	// printf("%x", d);
// // //  	// printf("\n");

	 
// // // 	// printf("======MON_PRINTF_HEX_MAJ=====\n");					// NOT WORKING
// // // 	// ft_printf("%X", d);
// // // 	// printf("\n");
// // // 	// printf("======OG_PRINTF_HEX_MAJ=====\n");
// // //  	// printf("%X", d);
// // //  	// printf("\n");
// }




// // /* ========================================================
// // Fu****g flags

// // */

// // /* ========================================================
// // Ptr still an Error with adresses 

// // */

// // /* ========================================================
// // J'avance jusqu'au % sinon j'ecris la string du printf

// // */