/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:13:53 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/20 14:32:19 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

char	*display_str(t_struct *s, va_list ap)
{
	char	*res;
	char	*tmp;
	char	*field;
	int		len_tmp;

	tmp = va_arg(ap, char *);
	len_tmp = ft_strlen(tmp);
	res = ft_strdup(tmp);
	res = check_precision(s, res);
	field = display_sp(s, len_tmp);
	if (!s->len_field)
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

char	*display_digit(t_struct *s, va_list ap, char conv)
{
	char *tmp;
	if (conv == 'd' || conv == 'i' || conv == 'D')
		tmp = conv_di(s, ap, conv);
	else
		tmp = conv_ouxx(s, ap, conv);
	return (tmp);
}
