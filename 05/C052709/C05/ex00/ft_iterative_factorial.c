/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:56:43 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/01 20:58:18 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb)
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
/*
int main(int ac, char **av){
	if (ac > 1)
	printf("%d\n",ft_iterative_factorial(atoi(av[1])));
			return 0;
}
*/
