/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:22:07 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/01 20:51:25 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
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
/*
int main(int ac, char **av)
{
        printf("%d\n", ft_iterative_power(atoi(av[1]), atoi(av[2])));
        return 0;
}*/
