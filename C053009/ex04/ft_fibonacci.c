/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:19:20 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/30 20:26:39 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_fibonacci(int index)
{
	int c = 1;		
	if(index > 1)
	{
	c = ft_fibonacci(index - 2) + ft_fibonacci(index -1);
	}
	if (index == 0)
		return 0;
	if (index < 0)
		return -1;
	return c;
}
/*
int main(int ac, char **av)
{
	printf("%d\n", ft_fibonacci(atoi(av[1])));
	return 0;
}*/
