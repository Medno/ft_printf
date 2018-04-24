/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:11:31 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/24 17:14:43 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_in_buffer(char buf[], char c)
{
	int	len;

	len = ft_strlen(buf);
	buf[len] = c;
}

char	*display_hex_oct(t_struct *s, char *str, char c, int pos)
{
	char	buf[4];
	char	*res;

	ft_bzero(buf, 4);
	if (s->flags & F_HASHTAG && (c == 'o' || c == 'O') && !ft_strequ(str, "0"))
		put_in_buffer(buf, '0');
	if ((s->flags & F_HASHTAG && (c == 'x' || c == 'X')
			&& pos) || c == 'p')
	{
		put_in_buffer(buf, '0');
		(c == 'x' || c == 'p') ? put_in_buffer(buf, 'x') : put_in_buffer(buf, 'X');
	}
	if (!ft_strchr("xXOouU", c))
	{
		(s->flags & F_PLUS && pos >= 0) ? put_in_buffer(buf, '+') : 0;
		(pos == -1) ? put_in_buffer(buf, '-') : 0;
		if (!(s->flags & F_PLUS) && !(s->flags & F_MINUS) && (s->flags & F_SPACE)
			&& pos >= 0)
			put_in_buffer(buf, ' ');
	}
	if (buf[0] != '\0')
		res = ft_strjoin(buf, str);
	else
		return (str);
	ft_strdel(&str);
	return (res);
}

char	*display_flags(t_struct *s, char *str, int pos)
{
	char	buf[4];
	char	*res;

	ft_bzero(buf, 4);
	(s->flags & F_PLUS && pos >= 0) ? put_in_buffer(buf, '+') : 0;
	(pos == -1) ? put_in_buffer(buf, '-') : 0;
	if (!(s->flags & F_PLUS) && !(s->flags & F_MINUS) && (s->flags & F_SPACE)
			&& pos > 0)
		put_in_buffer(buf, ' ');
	res = ft_strjoin(buf, str);
	ft_strdel(&str);
	return (res);
}

char	*display_field(int len_tmp, char to_print)
{
	char	buf[len_tmp + 1];
	int		i;
	char	*tmp;

	i = 0;
	while (i < len_tmp)
	{
		buf[i] = to_print;
		i++;
	}
	buf[i] = '\0';
	tmp = ft_strdup(buf);
	return (tmp);
}

char	*display_sp(t_struct *s, int len_tmp)
{
	char	to_print;
	char	*tmp;

	to_print = ' ';
	if ((s->flags & F_ZERO) && !(s->flags & F_MINUS))
		to_print = '0';
	tmp = NULL;
	if (s->len_field > len_tmp)
		tmp = display_field(s->len_field - len_tmp, to_print);
	return (tmp);
}

char	*check_precision_str(t_struct *s, char *tmp)
{
	char	*res;
	int		len;

	len = ft_strlen(tmp);
	if (s->precision != -1 && s->precision <= len)
	{
		res = ft_strndup(tmp, s->precision);
		ft_strdel(&tmp);
		return (res);
	}
	else
		return (tmp);
}

char	*display_sp_digit(t_struct *s, int len_tmp)
{
	int		len;
	char	to_print;
	char	*tmp;

	to_print = ' ';
	len = (s->precision == -1 || s->precision < len_tmp) ? len_tmp : s->precision;
	if ((s->flags & F_ZERO) && !(s->flags & F_MINUS) && len < s->len_field)
	{
		to_print = '0';
		tmp = display_field(s->len_field - len, to_print);
		return (tmp);
	}
	len = (s->precision == -1 || s->precision < len_tmp) ? len_tmp : s->precision;
	tmp = NULL;
	if (len < s->len_field)
		tmp = display_field(s->len_field - len, to_print);
	return (tmp);
}

char	*check_precision_digit(t_struct *s, char *tmp)
{
	int		len;
	int		len_tmp;
	char	*res;

	len_tmp = ft_strlen(tmp);
	len = (s->precision == -1) ? len_tmp : s->precision;
	res = NULL;
	if (s->precision > len_tmp)
	{
		res = display_field(s->precision - len_tmp, '0');
		res = ft_strjoindel(res, tmp);
	}
	else if (!s->precision && tmp[0] == '0')
		res = ft_strdup("");
	else
		return (tmp);
	ft_strdel(&tmp);
	return (res);
}

char	*dis_minus(t_struct *s, char *str, char *field)
{
	char	*last;

	if (!(s->flags & F_MINUS) && field && s->len_field > s->precision)
		last = ft_strjoin(field, str);
	else if ((s->flags & F_MINUS) && field && s->len_field > s->precision)
		last = ft_strjoin(str, field);
	else
		last = ft_strdup(str);
	ft_strdel(&str);
	ft_strdel(&field);
	return (last);
}

int		dis_len(t_struct *s, char *str, char c, int pos)
{
	int		len;
	int		len_fin;
	
	len = ft_strlen(str);
	len = ((s->flags & F_HASHTAG) && (c == 'x' || c == 'X')) ? len + 2 : len;
	len = ((s->flags & F_HASHTAG) && (c == 'o' || c == 'O')) ? len + 1 : len;
	len = ((pos == -1 || (s->flags & F_PLUS)) &&
		(c == 'D' || c == 'd' || c == 'i')) ? len + 1 : len;
	len = ((!(s->flags & F_PLUS) && (s->flags & F_SPACE)) &&
		(c == 'D' || c == 'd' || c == 'i')) ? len + 1 : len;
	len_fin = (s->precision != -1 && s->precision > len) ? s->precision : len;
	return (len_fin);
}

char	*dis_width_digit(t_struct *s, char *str, char c, int pos)
{
	int		len_fin;
	char	*tmp;
	char	*field;

	len_fin = dis_len(s, str, c, pos);
	if ((s->flags & F_ZERO) && s->precision == -1 && !(s->flags & F_MINUS) &&
			len_fin < s->len_field)
	{
		field = display_field(s->len_field - len_fin, '0');
		field = ft_strjoindel(field, str);
		tmp = display_hex_oct(s, field, c, pos);
		s->flags += ~(F_HASHTAG & F_PLUS & F_SPACE);
		return (tmp);
	}
	tmp = display_hex_oct(s, str, c, pos);
	len_fin = (s->precision == -1 || s->precision < (int)ft_strlen(tmp)) ?
		ft_strlen(tmp) : s->precision;
	if (len_fin < s->len_field)
	{
		field = display_field(s->len_field - len_fin, ' ');
		tmp = dis_minus(s, tmp, field);
	}
	return (tmp);
}
