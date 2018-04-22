/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:06:46 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/18 15:58:32 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	param;

	va_start(ap, format);
	init_struct(&param);
	parser(format, ap, &param);
	va_end(ap);
	//print_flag(param);
	write(1, param.str, param.len);
	ft_strdel(&(param.str));
	return (param.len);
}
