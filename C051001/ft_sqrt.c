#include <stdio.h>
#include <stdlib.h>

int ft_sqrt(int nb)
{
	int res = 1;
   	if (nb >= res * res && res < 43000)
		return (res += ft_sqrt(nb));
	if (nb == res * res)
		return res;
	return 0;
}

int main(int ac, char **av)
{
    printf("%d\n", ft_sqrt(atoi(av[1])));
    return 0;
}
