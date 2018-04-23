/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:11:31 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/23 18:01:19 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_in_buffer(char buf[], char c)
{
	int	len;

	len = ft_strlen(buf);
	buf[len] = c;
}

char	*display_hex_oct(t_struct *s, char *str, char conv, int pos)
{
	char	buf[4];
	char	*res;

	ft_bzero(buf, 4);
	if (s->flags & F_HASHTAG && conv == 'o' && str[0] != '0')
		put_in_buffer(buf, '0');
//printf("---buf : [%s]--- ---str : [%s]--- -- conv [%c]--\n", buf, str, conv);
	if ((s->flags & F_HASHTAG && (conv == 'x' || conv == 'X')
			&& str[0] != '0') || conv == 'p')
	{
		put_in_buffer(buf, '0');
		(conv == 'x' || conv == 'p') ? put_in_buffer(buf, 'x') : put_in_buffer(buf, 'X');
	}
	(s->flags & F_PLUS && pos == 1) ? put_in_buffer(buf, '+') : 0;
	(pos == -1) ? put_in_buffer(buf, '-') : 0;
	if (!(s->flags & F_PLUS) && !(s->flags & F_MINUS) && (s->flags & F_SPACE)
			&& pos)
		put_in_buffer(buf, ' ');
	res = ft_strjoin(buf, str);
	ft_strdel(&str);
//printf("---buf : [%s]--- ---str : [%s]--- -- conv [%c]--\n", buf, str, conv);
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
//printf("---buf : [%s]--- ---str : [%s]--- -- conv [%c]--\n", buf, str, conv);
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
	if ((s->flags & F_ZERO) && !(s->flags & F_MINUS))
		to_print = '0';
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
	else
		return (tmp);
	ft_strdel(&tmp);
	return (res);
}
