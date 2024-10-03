/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:57:33 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/01 21:46:36 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	if (nb > 1)
		return (nb *= ft_recursive_factorial(nb - 1));
	return (nb);
}
/*
int main(int ac, char **av)
{
        printf("%d\n", ft_recursive_factorial(atoi(av[1])));
        return 0;
}
*/
