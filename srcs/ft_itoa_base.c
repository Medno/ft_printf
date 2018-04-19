/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:42:01 by exam              #+#    #+#             */
/*   Updated: 2018/04/19 15:55:27 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static intmax_t	ft_abs(intmax_t n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int				nb_char(intmax_t n, int base)
{
	int	compt;

	compt = 0;
	while (n != 0)
	{
		compt++;
		n /= base;
	}
	return (compt);
}

char			*ft_itoa_base(intmax_t value, int base)
{
	int		nb_c;
	char	*res;
	char	labase[] = "0123456789ABCDEF";

	nb_c = nb_char(value, base);
	if (value == 0)
		return ("0");
	if (!(res = (char *)malloc(sizeof(char) * nb_c + 1)))
		return (NULL);
	res[nb_c] = '\0';
	nb_c--;
	while (value != 0)
	{
		res[nb_c] = labase[ft_abs(value % base)];
		value /= base;
		nb_c--;
	}
	return (res);
}
