/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:13:53 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/23 17:56:54 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*display_str(t_struct *s, va_list ap, int *len)
{
	char	*res;
	char	*tmp;
	char	*field;
	int		len_s;

	tmp = va_arg(ap, char *);
	if (!tmp && (*len = 6))
		return (ft_strdup("(null)"));
	res = ft_strdup(tmp);
	res = check_precision_str(s, res);
	len_s = ft_strlen(res);
	*len = (s->len_field > len_s) ? s->len_field : ft_strlen(res);
	if (!s->len_field)
		return (res);
	field = display_sp(s, len_s);
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

char	*display_char(t_struct *s, char tmp, int *len_tmp)
{
	char	*res;
	char	*field;

	res = NULL;
	ft_put_in_str(&res, (char)tmp);
	*len_tmp = (s->len_field) ? s->len_field : 1;
	if (!s->len_field)
		return (res);
	field = display_sp(s, 1);
	if (s->flags & F_MINUS)
	{
		res = ft_strjoinzero(res, field, 1, s->len_field);
		ft_strdel(&field);
		return (res);
	}
	field = ft_strjoinzero(field, res, *len_tmp - 1, 1);
	ft_strdel(&res);
	return (field);
}
