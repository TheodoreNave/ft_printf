/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:31:31 by tnave             #+#    #+#             */
/*   Updated: 2021/03/09 23:58:37 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <stdlib.h>

# define BUFF_MAX 256

typedef struct		s_pflist
{
	int			i;
	int			j;
	int			x;
	char		type;
	char		buff[BUFF_MAX];
	int			buff_len;
	int			neg;
	va_list		*iter;

}					t_pfstruct;

typedef struct		s_fllist
{
	int zero;
	int dash;
	int width;
	int nb_width;
	int	dot;
	int dot_prec;
	int ox;
}					t_pfconv;

int					ft_printf(const char *str, ...);
void				*ft_memset(void *b, int c, size_t len);
void				add_to_buff(t_pfstruct *pf, char c);
void				empty_buff(t_pfstruct *pf);
void				add_str_to_buff(t_pfstruct *pf, char *str);
int					ft_count_nbr(long nb, long base);
t_pfconv			*ft_parse(t_pfstruct *pf, t_pfconv *c_conv,
					const char *str);
t_pfconv			*ft_reset(t_pfconv *c_conv);
int					ft_type(char c);
char				is_int(char c);
char				is_u_int(char c);
char				is_hex(char c);
char				is_ptr(char c);
char				is_str(char c);
char				is_char(char c);
int					is_mod(char c);
int					ft_isdigit(int c);
int					ft_display_int(t_pfstruct *pf, t_pfconv *c_conv);
int					ft_display_u_int(t_pfstruct *pf, t_pfconv *c_conv);
int					ft_display_hex(t_pfstruct *pf, t_pfconv *c_conv);
int					ft_display_ptr(t_pfstruct *pf, t_pfconv *c_conv);
int					ft_display_str(t_pfstruct *pf, t_pfconv *c_conv);
int					ft_display_char(t_pfstruct *pf, t_pfconv *c_conv);
int					ft_display_mod(t_pfstruct *pf, t_pfconv *c_conv);
void				ft_putnbr_base(long nb, char *base, t_pfstruct *pf);
int					pf_putnbr(t_pfstruct *pf, long nb);
void				ft_padding(char c, t_pfstruct *pf, long len);
int					ft_max(long a, long b);
size_t				ft_strlen(char *str);
int					ft_atoi(const char *str, int *i);
void				ft_return_type(t_pfstruct *pf, t_pfconv *c_conv);
int					ft_before_diux(t_pfstruct *pf, t_pfconv *c_conv,
					long nb, long i);
void				ft_flags(t_pfstruct *pf, t_pfconv *c_conv);
int					ft_after(t_pfstruct *pf, t_pfconv *c_conv, long i);
int					ft_before_str(t_pfstruct *pf, t_pfconv *c_conv,
					char *str, int len);
int					ft_after_str_1(t_pfstruct *pf, t_pfconv *c_conv,
					char *str, int len);
int					ft_after_str_2(t_pfstruct *pf, t_pfconv *c_conv,
					char *str, int len);
int					print_begin(t_pfstruct *pf, t_pfconv *c_co,
					uintptr_t nb, int len);

#endif
