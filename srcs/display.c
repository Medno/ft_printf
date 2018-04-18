/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:12:04 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/18 16:31:09 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_flag(t_struct *s, char conv, int pos)
{
	if (s->flags & F_HASHTAG && conv == 'o' && s->len)
	{
		s->len++;
		ft_putchar('0');
	}
	if (s->flags & F_HASHTAG && (conv == 'x' || conv == 'X'))
	{
		s->len += 2;
		(conv == 'x') ? ft_putstr("0x") : ft_putstr("0X");
	}
	if (s->flags & F_PLUS && pos && s->len++)
		ft_putchar('+');
	if (!(s->flags & F_PLUS) && !(s->flags & F_MINUS) && (s->flags & F_SPACE)
			&& pos && s->len++)
		ft_putchar(' ');
}

void	display_field(int len_tmp, char to_print)
{
	char	buf[len_tmp + 1];
	int		i;

	i = 0;
	while (i < len_tmp)
	{
		buf[i] = to_print;
		i++;
	}
	buf[i] = '\0';
	ft_putstr(buf);
}

int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	display_sp(t_struct *s, int len_tmp, int minus)
{
	int		len;
	char	to_print;
	int		res_prec;

	to_print = ' ';
	if ((s->flags & F_ZERO) && !minus)
		to_print = '0';
	len = (s->precision == -1) ? len_tmp : s->precision;
	if (len < s->len_field)
		display_field(s->len_field - len, to_print);
	res_prec = (s->precision != -1 && s->precision < len_tmp) ? s->precision :
		len_tmp;
	s->len += ft_max(s->len_field, res_prec);
}

void	display_str(t_struct *s, va_list ap)
{
	char	*tmp;
	int		len_tmp;

	tmp = va_arg(ap, char *);
	len_tmp = ft_strlen(tmp);
	if (!(s->flags & F_MINUS))
		display_sp(s, len_tmp, 0);
	(s->precision != -1 && s->precision <= len_tmp) ?
		ft_putnstr(tmp, s->precision) : ft_putstr(tmp);
	if (s->flags & F_MINUS)
		display_sp(s, len_tmp, 1);
}

void	display_digit(t_struct *s, va_list ap, char conv)
{
	display_flag(s, conv, 0);
}
