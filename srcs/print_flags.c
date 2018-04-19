#include "ft_printf.h"

void	print_flag(t_struct s)
{
	if (s.flags & F_HASHTAG)
		ft_putstr("Hashtag dans les flags\n");
	if (s.flags & F_ZERO)
		ft_putstr("Zero dans les flags\n");
	if (s.flags & F_MINUS)
		ft_putstr("Minus dans les flags\n");
	if (s.flags & F_SPACE)
		ft_putstr("Space dans les flags\n");
	if (s.flags & F_PLUS)
		ft_putstr("Plus dans les flags\n");
//	if (s.flags & F_QUOTE)
//		ft_putstr("Quote dans les flags\n");
	if (s.len_field > 0)
		ft_putnbr(s.len_field);
	ft_putchar(' ');
	if (s.precision > 0)
		ft_putnbr(s.precision);
	if (s.modif == F_HH)
		ft_putstr("HH detecte");
	if (s.modif == F_H)
		ft_putstr("H detecte");
	if (s.modif == F_LL)
		ft_putstr("LL detecte");
	if (s.modif == F_L)
		ft_putstr("L detecte");
	if (s.modif == F_J)
		ft_putstr("J detecte");
	if (s.modif == F_Z)
		ft_putstr("Z detecte");

}
