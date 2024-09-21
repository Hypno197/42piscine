#include<unistd.h>

void ft_ultimate_div_mod(int *a, int *b)
{
	int div = *a/\*b;
	int res = *a%*b;
	*a = div;
	*b = res;
}
