/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_majc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:00:29 by pchadeni          #+#    #+#             */
/*   Updated: 2018/05/04 16:11:05 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	first_st(wchar_t c, char uni[4])
{
	uni[0] = c;
	return (1);
}

int	second_st(wchar_t c, char uni[4])
{
	uni[0] = (c >> 6) | 0xC0;
	uni[1] = (c & 0x3F) | 0x80;
	return (2);
}

int	third_st(wchar_t c, char uni[4])
{
	uni[0] = (c >> 12) | 0xE0;
	uni[1] = ((c >> 6) & 0x3F) | 0x80;
	uni[2] = (c & 0x3F) | 0x80;
	return (3);
}

int forth_st(wchar_t c, char uni[4])
{
	uni[0] = (c >> 18) | 0xF0;
	uni[1] = ((c >> 12) & 0x3F) | 0x80;
	uni[2] = ((c >> 6) & 0x3F) | 0x80;
	uni[3] = (c & 0x3F) | 0x80;
	return (4);
}

int	check_chart(wchar_t c, char uni[4])
{
	if ((c >= 0xD800 && c <= 0xDFFF) || /*(c >= 0x30000 && c <= 0xDFFFF) ||*/
			c > 0x10FFFF || c < 0 || c == 256)
		return (-1);
	if (c < 128)
		return (first_st(c, uni));
	else if (c <= 0x7FF)
		return (second_st(c, uni));
	else if (c <= 0xFFFF)
		return (third_st(c, uni));
	else if (c <= 0x10FFFF)
		return (forth_st(c, uni));
	return (-1);
}

char	*display_uni(t_struct *s, wchar_t tmp)
{
	char	uni[5];
	char	*tmp_s;
//	char	*res;

	ft_bzero(uni, 5);
//printf("wchar_t : [%d]\n", tmp);
	if (check_chart(tmp, uni) == -1)
		return (exit_printf(s));
	tmp_s = ft_strdup(uni);
//printf("len : %zu\n", ft_strlen(tmp_s));
	return (tmp_s);
//	res = display_char(s, tmp, len_tmp);
//	ft_strdel(&tmp_s);
//	return (display_str(s, tmp_s, len_tmp, 's'));
}

char	*conv_majc(t_struct *s, va_list ap, int *len_tmp)
{
	char	*tmp;
	wchar_t	get;

	get = va_arg(ap, wchar_t);
	tmp = display_uni(s, get);
	if (tmp)
		tmp = display_char(s, tmp, len_tmp);
	return (tmp);
}
