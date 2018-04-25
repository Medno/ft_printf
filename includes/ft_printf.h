/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:33:42 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/25 17:39:21 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
			#include <stdio.h>
# define F_HASHTAG	1
# define F_ZERO		2
# define F_MINUS	4
# define F_SPACE	8
# define F_PLUS		16
//# define F_QUOTE	32

# define F_HH		1
# define F_H		2
# define F_L		3
# define F_LL		4
# define F_J		5
# define F_Z		6

typedef struct	s_struct
{
	int		flags;
	int		precision;
	int		len_field;
	int		modif;
	int		len;
	char	*str;
}				t_struct;

int				ft_printf(const char *format, ...);
void			parser(const char *f, va_list va, t_struct *s);
t_struct		*field_preci(const char *format, int *i, t_struct *s);
t_struct		*check_flags(const char *format, int *i, t_struct *s);
void			init_struct(t_struct *s);
void			reinit_struct(t_struct *s);

char			*display_flags(t_struct *s, char *str, int pos);
char			*display_hex_oct(t_struct *s, char *str, char conv, int pos);
char			*display_str(t_struct *s, char *tmp, int *len_tmp, int conv);
char			*display_digit(t_struct *s, va_list ap, char conv, int *len);
char			*display_char(t_struct *s, char tmp, int *len_tmp);
char			*display_sp(t_struct *s, int len_tmp);
char			*display_sp_digit(t_struct *s, int len_tmp);
char			*display_uni(t_struct *s, va_list ap, int *len_tmp);
char			*get_str(t_struct *s, va_list ap, int *len, int conv);
char			*get_char_va(t_struct *s, va_list ap, int *len_tmp, int c);

void			put_in_struct(const char *f, int i, t_struct *s);
char			*check_precision_str(t_struct *s, char *tmp);
char			*check_precision_digit(t_struct *s, char *tmp, char c);
char			*dis_width_digit(t_struct *s, char *str, char conv, int pos);
t_struct		*last_check(t_struct *s, char c);

char			*ft_itoa_base(intmax_t value, int base);
char			*ft_utoa_base(uintmax_t value, int base);
char			*conv_di(t_struct *s, va_list ap, char c);
char			*conv_ouxx(t_struct *s, va_list ap, char c);
char			*conv_p(t_struct *s, va_list ap, int *len);
int				nb_char_u(uintmax_t n, int base);
int				nb_char(intmax_t n, int base);

int				is_convert(char c);
int				is_flag(char c);
int				digit_conv(char c);

int				exit_printf(t_struct *s);

char			*ft_strjoinzero(char *s1, char *s2, int len1, int len2);
//todel
void	print_flag(t_struct s);
#endif
