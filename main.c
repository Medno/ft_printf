#include "includes/ft_printf.h"
# include <stdio.h>
int		main()
{
	char *tutu = "bonjour";
	int	res;
printf("------------- Test des str : -------------\n");

	res =    printf("Real [%s] ", tutu); printf("Resultat : [%d]\n", res);
	res = ft_printf("Mine [%s] ", tutu); printf("Resultat : [%d]\n", res);

	res =    printf("Real [% +10.1s] ", tutu); printf("Resultat : [%d]\n", res);
	res = ft_printf("Mine [% +10.1s] ", tutu); printf("Resultat : [%d]\n", res);

	res =    printf("tutu [%#0 +10.1s] toto ", tutu); printf("Resultat : [%d]\n", res);
	res = ft_printf("tutu [%#0 +10.1s] toto ", tutu); printf("Resultat : [%d]\n", res);

printf("------------- Test des digit : -------------\n");
	res =    printf("Real [%+d] ", 42); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%+d] ", 42); printf("Res : [%d]\n", res);

	res =    printf("Real [%x] ", -42); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%x] ", -42); printf("Res : [%d]\n", res);

	res =    printf("Real [%+d] ", -42); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%+d] ", -42); printf("Res : [%d]\n", res);

	res =    printf("Real [%010#+x] ", -42); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%010#+x] ", -42); printf("Res : [%d]\n", res);

	res =    printf("Real [%010#+x] ", -0); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%010#+x] ", -0); printf("Res : [%d]\n", res);

printf("Octal :\n");
	res =    printf("Real [%o] ", -42); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%o] ", -42); printf("Res : [%d]\n", res);

	res =    printf("Real [%+o] ", -42); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%+o] ", -42); printf("Res : [%d]\n", res);

	res =    printf("Real [%010#+o] ", -42); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%010#+o] ", -42); printf("Res : [%d]\n", res);

	res =    printf("Real [%010#+o] ", -0); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%010#+o] ", -0); printf("Res : [%d]\n", res);


	res =    printf("Real [%010#+c] ", '\0'); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%010#+c] ", '\0'); printf("Res : [%d]\n", res);
	res =    printf("Real [%c] ", '\0'); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%c] ", '\0'); printf("Res : [%d]\n", res);

  ft_printf("Test de chiffre sans h : %d, et %d\n", 432767, -432767);
  printf("Test de chiffre sans h : %d, et %d\n", 432767, -432767);
  printf("Test de chiffre avec h : %hd, et %hd\n", 432767, -432767);
  ft_printf("Test de chiffre avec h : %hd, et %hd\n", 432767, -432767);

	res =    printf("Real [%010#+c] ", 'a'); printf("Res : [%d]\n", res);
	res =    printf("Real [%0.10#+c] ", 'a'); printf("Res : [%d]\n", res);
	res =    printf("Real [% c] ", 'a'); printf("Res : [%d]\n", res);


//	res = printf("Real [%0+#10x] ", -42);
//	res = printf("Real [%0+#10x] ", -0);
	int i = 0;
	int j = 0;

//	ft_printf("test", tutu);
//	printf("%1$4s %2$10s %3$10s\n", "obj", "qty", "price");
//	printf("%1$4s %2$10s %3$10s\n", "----", "----", "-----");
//	printf("%1$4s %2$10s %3$10s\n", "tomato", "1kg", "15");
//	printf("%3$4s %2$10s %1$10s\n", "20", "2kg", "potato");
//	printf("%1$4s %2$10s %3$10s\n", "tomato", "1kg", "15");
}
