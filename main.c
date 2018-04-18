#include "includes/ft_printf.h"
# include <stdio.h>
int		main()
{
	char *tutu = "bonjour";
	int	res;
	res = ft_printf("tutu [%#0 +10.1s] toto\n", tutu);
	printf("Resultat : [%d]\n", res);
	res = printf("tutu [%#0 +10.1s] toto\n", tutu);
	printf("Resultat : [%d]\n", res);
	int i = 0;
	int j = 0;
//	ft_printf("test", tutu);
//	printf("%1$4s %2$10s %3$10s\n", "obj", "qty", "price");
//	printf("%1$4s %2$10s %3$10s\n", "----", "----", "-----");
//	printf("%1$4s %2$10s %3$10s\n", "tomato", "1kg", "15");
//	printf("%3$4s %2$10s %1$10s\n", "20", "2kg", "potato");
//	printf("%1$4s %2$10s %3$10s\n", "tomato", "1kg", "15");
}
