/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_modif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:17:02 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/19 15:55:21 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*final_digit(t_struct *s, char *t, int sign, char c)
{
	char	*tmp;
	int		to_add;
	int		len;

	len = ft_strlen(t);
	tmp = ft_strdup("");
	if (s->flags & F_ZERO && !(s->flags & F_MINUS))
		to_add = display_sp(s, len);
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
	tmp = final_digit();
	return (tmp);
}

char	*conv_ouxx(t_struct *s, va_list ap, char c)
{
	uintmax_t	res;
	char		*tmp;

	res = va_arg(ap, uintmax_t);
	res = (s->modif == F_HH) ? (unsigned char)res : res;
	res = (s->modif == F_H) ? (unsigned short)res : res;
	res = (s->modif == F_L || c == 'U' || c == 'O') ? (unsigned long)res : res;
	res = (s->modif == F_LL) ? (unsigned long long)res : res;
	res = (s->modif == F_J) ? (uintmax_t)res : res;
	res = (s->modif == F_Z) ? (size_t)res : res;
	res = (!s->modif) ? (unsigned int)res : res;
	if (c == 'x' || c == 'X')
		tmp = ft_itoa_base(res, 16);
	else if (c == 'o')
		tmp = ft_itoa_base(res, 8);
	if (c == 'x')
		tmp = ft_stolower(tmp);
	return (tmp);
}
