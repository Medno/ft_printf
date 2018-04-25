/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_modif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:17:02 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/25 14:24:50 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*final_digit(t_struct *s, char *t, int sign, char c)
{
	char	*last;
	int		len;
	char	*field;
	char	*res;

	len = (sign == -1) ? ft_strlen(t) + 1 : ft_strlen(t);
	field = NULL;
	last = ft_strdup(t);
	last = check_precision_digit(s, last, c);
	len = ft_strlen(last);
	res = dis_width_digit(s, last, c, sign);
	ft_strdel(&field);
	ft_strdel(&t);
	return (res);
}

char	*conv_di(t_struct *s, va_list ap, char c)
{
	intmax_t	res;
	char		*tmp;
	int			sign;

	res = va_arg(ap, intmax_t);
	res = (s->modif == F_HH) ? (signed char)res : res;
	res = (s->modif == F_H) ? (short)res : res;
	res = (s->modif == F_L || c == 'D') ? (long)res : res;
	res = (s->modif == F_LL) ? (long long)res : res;
	res = (s->modif == F_J) ? (intmax_t)res : res;
	res = (s->modif == F_Z) ? (ssize_t)res : res;
	res = (!s->modif) ? (int)res : res;
	tmp = ft_itoa_base(res, 10);
	if (res > 0)
		sign = 1;
	else
		sign = (res < 0) ? -1 : 0;
	tmp = final_digit(s, tmp, sign, c);
	return (tmp);
}

char	*conv_ouxx(t_struct *s, va_list ap, char c)
{
	uintmax_t	res;
	char		*tmp;

	res = va_arg(ap, uintmax_t);
	res = (s->modif == F_HH) ? (unsigned char)res : res;
	res = (s->modif == F_H) ? (unsigned short)res : res;
	res = (s->modif == F_L) ? (unsigned long)res : res;
	res = (s->modif == F_LL) ? (unsigned long long)res : res;
	res = (s->modif == F_J) ? (uintmax_t)res : res;
	res = (s->modif == F_Z) ? (size_t)res : res;
	res = (!s->modif) ? (unsigned int)res : res;
	if (!res)
		tmp = ft_strdup("0");
	else if (c == 'x' || c == 'X')
		tmp = ft_utoa_base(res, 16);
	else if (c == 'o' || c == 'O')
		tmp = ft_utoa_base(res, 8);
	else
		tmp = ft_utoa_base(res, 10);
	if (c == 'x' && tmp)
		tmp = ft_stolower(tmp);
	if (!res)
		tmp = final_digit(s, tmp, 0, c);
	else
		tmp = final_digit(s, tmp, 1, c);
/*
	if (res && (c == 'x' || c == 'X'))
		tmp = final_digit(s, tmp, 1, c);
	else if (c == 'x' || c == 'X')
		tmp = final_digit(s, tmp, 0, c);
	else
		tmp = final_digit(s, tmp, 0, c);
*/
	return (tmp);
}

char	*conv_p(t_struct *s, va_list ap, int *len)
{
	uintmax_t	p;
	char		*tmp;

	p = va_arg(ap, uintmax_t);
	tmp = ft_utoa_base(p, 16);
	tmp = ft_stolower(tmp);
	s->modif = F_L;
	s->flags |= F_HASHTAG;
	tmp = final_digit(s, tmp, 0, 'p');
	*len = ft_strlen(tmp);
	return (tmp);
}
