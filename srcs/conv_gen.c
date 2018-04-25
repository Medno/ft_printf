/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:13:53 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/25 17:47:42 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_str(t_struct *s, va_list ap, int *len, int conv)
{
	char	*tmp;

	tmp = va_arg(ap, char *);
	return (display_str(s, tmp, len, conv));
}

char	*display_str(t_struct *s, char *tmp, int *len, int conv)
{
	char	*res;
	char	*field;
	int		len_s;
(void)conv;
	res = (!tmp && (*len = 6)) ? res = ft_strdup("(null)") : ft_strdup(tmp);
	res = check_precision_str(s, res);
	len_s = ft_strlen(res);
	*len = (s->len_field > len_s) ? s->len_field : len_s;
	if (!s->len_field)
		return (res);
	field = display_sp(s, len_s);
	if (!field)
		return (res);
	if (s->flags & F_MINUS)
	{
		res = ft_strjoindel(res, field);
		ft_strdel(&field);
		return (res);
	}
	field = ft_strjoindel(field, res);
	ft_strdel(&res);
	return (field);
}

char	*display_digit(t_struct *s, va_list ap, char conv, int *len_tmp)
{
	char *tmp;

	if (conv == 'd' || conv == 'i' || conv == 'D')
		tmp = conv_di(s, ap, conv);
	else
		tmp = conv_ouxx(s, ap, conv);
	*len_tmp = ft_strlen(tmp);
	return (tmp);
}

char	*get_char_va(t_struct *s, va_list ap, int *len_tmp, int c)
{
	//char			buf[2];
	char			*res;
	unsigned char	tmp;

	if (c == -1)
		tmp = (unsigned char)va_arg(ap, int);
	else
		tmp = c;
	res = display_char(s, tmp, len_tmp);
//	res = display_char(s, buf, len_tmp);
	return (res);
}

char	*display_char(t_struct *s, char tmp, int *len_tmp)
{
	char	*res;
	char	*field;
	int		len;

	len = 1;
	res = NULL;
	ft_put_in_str(&res, (char)tmp);
	*len_tmp = (s->len_field) ? s->len_field : len;
	if (!s->len_field)
		return (res);
	field = display_sp(s, len);
	if (s->flags & F_MINUS)
	{
		res = ft_strjoinzero(res, field, len, s->len_field);
		ft_strdel(&field);
		return (res);
	}
	field = ft_strjoinzero(field, res, *len_tmp - len, len);
	ft_strdel(&res);
	return (field);
}
