#include <stdio.h>
#include <stdlib.h>

int ft_iterative_factorial(int nb)
{
	int	val;

	val = 1;
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	while (nb >= 2)
	{
		val = val * (nb);
		nb--;
	}
	return (val);
}

int main(int ac, char **av){
	if (ac > 1)
	printf("%d\n",ft_iterative_factorial(atoi(av[1])));
			return 0;
}
