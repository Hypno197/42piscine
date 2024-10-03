/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:42:15 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/01 21:53:37 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb)
{
	int	res;

	res = 1;
	while (nb != res * res && res < 43640)
		res++;
	if (nb == res * res)
		return (res);
	return (0);
}
/*
int main(int ac, char **av)
{
	printf("%d\n", ft_sqrt(atoi(av[1])));
	return 0;
}
*/
