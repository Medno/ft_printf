/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:33:42 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/17 19:03:37 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define F_HASHTAG	1
# define F_ZERO		2
# define F_MINUS	4
# define F_SPACE	8
# define F_PLUS		16
# define F_QUOTE	32

typedef struct	s_struct
{
	int		flags;
	int		precision;
	int		len_field;
	size_t	len;
}				t_struct;

int				ft_printf(const char *format, ...);
void			ft_putstr(const char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void			ft_putnstr(const char *s, size_t len);
size_t			ft_strlen(const char *s);
int				ft_isdigit(int a);
int				ft_isalpha(int c);

void			parser(const char *f, va_list va, t_struct *s);
//todel
void	print_flag(t_struct s);
#endif
