#include "ft_printf.h"

int		digit_conv(char c)
{
	if (ft_strchr("dDoOuUixX", c))
		return (1);
	return (0);
}

int		is_flag(char c)
{
	if (ft_strchr("#0- +.hljz", c))
		return (1);
	return (0);
}

int		is_convert(char c)
{
	if (ft_strchr("sSpdDioOuUxXcC", c))
		return (1);
	return (0);
}
