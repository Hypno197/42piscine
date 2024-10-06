/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:15:01 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/01 21:54:49 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int nb)
{
	int	a;

	a = 1;
	if (nb < 2)
		return (0);
	while (++a < nb)
		if (nb % a == 0)
			return (0);
	return (1);
}
/*
int main(int ac, char **av)
{
	printf("%d\n", ft_is_prime(atoi(av[1])));
	return 0;
}*/
