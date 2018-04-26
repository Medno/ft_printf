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

	res =    printf("xReal [%x] ", -42); printf("Res : [%d]\n", res);
	res = ft_printf("xMine [%x] ", -42); printf("Res : [%d]\n", res);

	res =    printf("Real [%+d] ", -42); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%+d] ", -42); printf("Res : [%d]\n", res);

	res =    printf("010#+Real [%010#+x] ", -42); printf("Res : [%d]\n", res);
	res = ft_printf("010#+Mine [%010#+x] ", -42); printf("Res : [%d]\n", res);

	res =    printf("010#+Real [%010#+x] ", -0); printf("Res : [%d]\n", res);
	res = ft_printf("010#+Mine [%010#+x] ", -0); printf("Res : [%d]\n", res);

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

	  printf("%5.6x\n", 5427);
	  ft_printf("%5.6x\n", 5427);

	  printf("%5 .20x\n", 5427);
	  ft_printf("%5 .20x\n", 5427);

	res =    printf("Real [%s] ", NULL); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%s] ", NULL); printf("Res : [%d]\n", res);
ft_printf("[%-10x]\n", 42);
ft_printf("[%s]\n", NULL);
printf("[%s]\n", NULL);

ft_printf("% u", 4294967295);
ft_printf("%%\n");

	res =    printf("08xReal [%#08x] ", 42); printf("Res : [%d]\n", res);
	res = ft_printf("08xMine [%#08x] ", 42); printf("Res : [%d]\n", res);

	res =    printf("Real [%2c] ", '\0'); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%2c] ", '\0'); printf("Res : [%d]\n", res);

	res =    printf("Real [%.2s] is a string", ""); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%.2s] is a string", ""); printf("Res : [%d]\n", res);

	res =    printf("Real [%5%] is a string\n"); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%5%] is a string\n"); printf("Res : [%d]\n", res);
int	po;
	res =    printf("Real [%p]\n", &po); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%p]\n", &po); printf("Res : [%d]\n", res);

	printf("%O\n", LONG_MAX);
	ft_printf("%O\n", LONG_MAX);

	res =    printf("#lxReal [%#lx]\n", 0); printf("Res : [%d]\n", res);
	res = ft_printf("#lxMine [%#lx]\n", 0); printf("Res : [%d]\n", res);

	res =    printf("Real [%p]\n", NULL); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%p]\n", NULL); printf("Res : [%d]\n", res);

	res =    printf("Real [%-05d] ", -42); printf("Res : [%d]\n", res);
	res = ft_printf("Mine [%-05d] ", -42); printf("Res : [%d]\n", res);
	printf("%03.2d\n", 0);
	ft_printf("%03.2d\n", 0);

	printf("%0+5d\n", -42);
	ft_printf("%0+5d\n", -42);

	  printf("%05d\n", -42);
	  ft_printf("%05d\n", -42);
ft_printf("{%-15Z}\n", 123);
printf("{%-15Z}\n", 123);


printf("%");
ft_printf("%");
printf(" 03{% 03d}\n", 0);
ft_printf(" 03{% 03d}\n", 0);
printf("{% 03x}\n", 42);
ft_printf("{% 03x}\n", 42);
printf("010d{%010d}\n", -42);
ft_printf("010d{%010d}\n", -42);

res =    printf("#.O [%#.O]", 0);  printf("Res : [%d]\n", res);
res = ft_printf("#.O [%#.O]", 0); printf("Res : [%d]\n", res);

res =    printf(".O [%.O]", 0);  printf("Res : [%d]\n", res);
res = ft_printf(".O [%.O]", 0); printf("Res : [%d]\n", res);

res =    printf("#O [%#O]", 0);  printf("Res : [%d]\n", res);
res = ft_printf("#O [%#O]", 0); printf("Res : [%d]\n", res);

res =    printf("#.o [%#.o]", 0);  printf("Res : [%d]\n", res);
res = ft_printf("#.o [%#.o]", 0); printf("Res : [%d]\n", res);

res =    printf(".o [%.o]", 0);  printf("Res : [%d]\n", res);
res = ft_printf(".o [%.o]", 0); printf("Res : [%d]\n", res);

res =    printf("#o [%#o]", 0);  printf("Res : [%d]\n", res);
res = ft_printf("#o [%#o]", 0); printf("Res : [%d]\n", res);

printf("#.X [%#.X]\n", 0);
ft_printf("#.X [%#.X]\n", 0);

printf("#o%#o\n", 0);
ft_printf("#o%#o\n", 0);

printf("%1.4s et %-6.8s et %4.2s\n", "tuuu", "12345", "hu");
ft_printf("%1.4s et %-6.8s et %4.2s\n", "tuuu", "12345", "hu");

ft_printf("Test C : [%C]\n", 0x03D5);
ft_printf("Test C : [%C]\n", '0');

printf("test%#.4o et %02o %0#14.0o!!\n", 012, 036, 12587499);
ft_printf("test%#.4o et %02o %0#14.0o!!\n", 012, 036, 12587499);

printf("titi % +---12.5% et%%%0004% et %+1%\n");
ft_printf("titi % +---12.5% et%%%0004% et %+1%\n");

	printf("%.p, %.0p\n", 0, 0);
	ft_printf("%.p, %.0p\n", 0, 0);

	printf("Real : [%d]\n",    printf("%.C\n", 0));
	ft_printf("Mine : [%d]\n", ft_printf("%.C\n", 0));

	printf("Real : [%d]\n", printf("%lc\n", 254));
	ft_printf("Mine : [%d]\n", ft_printf("%lc\n", 254));

	printf("real : [% -56.18zi]\n", 0);
	ft_printf("mine : [% -56.18zi]\n", 0);

	printf("real : [% 042hhi]\n", 1261665231);
	ft_printf("mine : [% 042hhi]\n", 1261665231);

	printf("real : [%0#54ho]\n", 1891602244);
	ft_printf("mine : [%0#54ho]\n", 1891602244);

	printf("real : [%-#.42llo]\n", 1891602244);
	ft_printf("mine : [%-#.42llo]\n", 1891602244);

	printf("real : [%-1.28zo]\n", 1891602244);
	ft_printf("mine : [%-1.28zo]\n", 1891602244);
}
