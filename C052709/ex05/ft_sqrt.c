/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:42:15 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/01 12:14:57 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_sqrt(int nb)
{	int res = 1;
	if (nb == res*res)
		return res;
	else if(res < 43640)
		res += ft_sqrt(nb);
	else 
		return 0;
	 if (nb == res*res)
		 return res;
	return res;
}

int main(int ac, char **av)
{
	printf("%d\n", ft_sqrt(atoi(av[1])));
	return 0;
}
