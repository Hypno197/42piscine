#include <stdio.h>
#include <stdlib.h>

int ft_recursive_factorial(int nb)
{
	if (nb < 1)
		return 0;
	if (nb > 1)
	return (nb *= ft_recursive_factorial(nb-1));

	return nb;
}

int main(int ac, char **av)
{
        printf("%d\n", ft_recursive_factorial(atoi(av[1])));
        return 0;
}
