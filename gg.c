#include <stdio.h>
#include "includes/ft_printf.h"
int main ()
{
	/*int a = -4;
	int b = 4;
	int i = -65;
	char *j = "oui";
	int k = -19;
	int l = 22;
	int m = 8;
	int c = -1;
	int d = 0;
	int e = -1;
	int count = 0;
	while (count < 15)
	{
		printf("\n*******************\ntest %d :\n\n", count);
		printf("%0*.*x, %*p, %00*.*d, %--*.*d, %0*.*u, %0*.*d, %0*.*d, %0*.*d", a, b, i, b, &j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
	printf("\n");
		ft_printf("%0*.*x, %*p, %00*.*d, %--*.*d, %0*.*u, %0*.*d, %0*.*d, %0*.*d", a, b, i, b, &j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
	a = a + 1;
	a = a * (-1);
	b = b - 2;
	i = i / 5;
	e = e * (-1);
		if (count % 2 == 0)
		{
			k = 0;
			d = -1;
			m = -19;
			c = 11;
		}
	count++;
	}*/
	printf("expected : \n");
	ft_printf("%--150.*d%01.172i%--151.122d%--*.16x%--23.182%" ,193,-1523409169,453642614,881460015,68,2920216226u);
	printf("\nactual : \n");
	printf("%--150.*d%01.172i%--151.122d%--*.16x%--23.182%" ,193,-1523409169,453642614,881460015,68,2920216226u);
	return (0);
}
