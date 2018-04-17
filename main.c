#include "includes/ft_printf.h"
# include <stdio.h>
int		main()
{
	char *tutu = "bonjour";
	ft_printf("tutu\n %#0- +'3.01s toto\n", tutu);
//	ft_printf("test", tutu);
//	printf("%1$4s %2$10s %3$10s\n", "obj", "qty", "price");
//	printf("%1$4s %2$10s %3$10s\n", "----", "----", "-----");
//	printf("%1$4s %2$10s %3$10s\n", "tomato", "1kg", "15");
//	printf("%3$4s %2$10s %1$10s\n", "20", "2kg", "potato");
//	printf("%1$4s %2$10s %3$10s\n", "tomato", "1kg", "15");
}
