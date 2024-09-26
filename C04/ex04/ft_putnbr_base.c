/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:47:17 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/26 20:56:40 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		str++;
		c++;
	}
	return (c);
}

void ft_putnbr_base(int nbr, char *base)
{
	int	bl;
	
	bl = ft_strlen(base);
	if (bl < 2)
		return;
    if (nbr == -2147483648)
	{
		write(1, "-", 1);
		return ft_putnbr_base(2147483647, base);
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;	
	}
	if (nbr >= bl)
	{
		ft_putnbr_base((nbr / bl), base);
		nbr = nbr % bl;
	}
	if (nbr < bl)
	{
		write(1, &base[nbr], 1);
	}
}
