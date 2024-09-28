/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:47:17 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/28 17:07:47 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		while (str[c] != '\0')
		{
			if ((str[i] == str[c] && i != c) || str[c] == ' ')
				return (0);
			if (str[c] == '+' || str[c] == '-')
				return (0);
			c++;
		}
		c = 0;
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	bl;

	bl = ft_strlen(base);
	if (bl < 2)
		return ;
	if (nbr == -2147483648)
	{
		ft_putnbr_base((-2147483648 / bl), base);
		nbr = (-2147483648 % bl) * -1;
		write(1, &base[nbr], 1);
		return ;
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
	write(1, &base[nbr], 1);
}
