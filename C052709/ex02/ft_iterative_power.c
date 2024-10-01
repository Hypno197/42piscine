#include <stdio.h>
#include <stdlib.h>

int ft_iterative_power(int nb, int power)
{	
	int	res;

	res = nb;
	while(power > 1)
	{
		res *= nb;
		power--;
	}
	if (power == 0)
		return 1;
	return res;
}

int main(int ac, char **av)
{
        printf("%d\n", ft_iterative_power(atoi(av[1]), atoi(av[2])));
        return 0;
}
