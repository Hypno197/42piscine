/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:15:01 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/01 21:55:37 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_find_next_prime(int nb)
{
	int	a;

	a = 2;
	while (a < nb)
	{
		nb++;
		while (a <= nb)
		{
			if (a == nb)
				return (nb);
			if (nb % a == 0)
				break ;
			a++;
		}
		a = 2;
	}
	return (2);
}
/*
int main(int ac, char **av)
{
	printf("%d\n", ft_find_next_prime(atoi(av[1])));
	return 0;
}
*/
