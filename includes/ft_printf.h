/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:31:31 by tnave             #+#    #+#             */
/*   Updated: 2021/02/26 15:48:32 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <strings.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <libc.h>
# define BUFF_MAX 12

typedef struct      d_list
{
	int 	i;
	int		j;
	int		x;					// Total_len
	char 	y;
	char	stock;
	char 	*arg;
	char	type;
	char	buf[BUFF_MAX];

} 					pfstruct; 

typedef struct		s_list
{
	int width;	//number after width -> -45
	int prec;	// Check 0 puis -1 en valeur
	int	dot; 	// .
	int	conv; 	// type
	//int star; 	// *
	int zero;	// 0
	int dash;	// -

}					pfconv;

void		ft_putchar(char c);										// PUTCHAR
int			pf_putnbr(pfstruct *type, long nb);
int			ft_display_int(pfstruct *type, pfconv c_conv, va_list iter);			// DISPLAY INTEGER
int			ft_printf(const char *str, ...);						// MAIN_FUNCTION
int			fonction_type(pfstruct *type, char c);								
void		ft_putnbr_base(long nb, char *base, pfstruct *pf);
void		ft_putstr(char *str);									// PUTSTR
size_t		ft_strlen(char *str);									// LEN
char		*ft_strrev(char *str);									// REV FOR ITOA
void		add_to_buff(pfstruct *pf, char c);						// ADDED FOR BUFFER
void		empty_buff(pfstruct *pf);								// EMPTY THE BUFFER
pfconv		init_conv(char *str, char conv);
//int		ft_atoi(char *str);
int			ft_count_nbr(long nb, long base);							// COUNT NBR ITOA
char		*ft_strlowcase(char *str);
char		is_int(char c);
char		is_ptr(char c);
char 		is_hex(char c);
char		is_str(char c);
char		is_char(char c);
int			ft_display_hex(pfstruct *type, pfconv c_conv, va_list iter);
int			ft_display_ptr(pfstruct *type, pfconv c_conv, va_list iter);
int     	ft_display_str(pfstruct *type, pfconv c_conv, va_list iter);
int     	ft_display_char(pfstruct *type, pfconv c_conv, va_list iter);
int			ft_display_modu(pfstruct *type, pfconv c_conv);
int			ft_display_unsigned_int(pfstruct *type, pfconv c_conv, va_list iter);
char		is_u_int(char c);
int			ft_isdigit(int c);
pfconv		*ft_parse(pfconv *c_conv, const char *str, va_list iter);
char		is_width(char c);
char		is_prec(char c);
int 		ft_display_width_d(pfstruct *type, pfconv c_conv, va_list iter);
int			check_type(char c);
int			ft_display_int_width(pfstruct *type, pfconv c_conv, int j);
int			ft_type(char c);
int			ft_display_u_int(pfstruct *type, pfconv c_conv, va_list iter);
void		padding(char c, pfstruct *type, long len);
int			max(long a, long b);
void		add_str_to_buff(pfstruct *pf, char *str);
int			ft_mod(char c);

#endif