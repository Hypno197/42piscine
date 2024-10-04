/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:05:51 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/04 11:20:46 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = (nb * -1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		c = nb + 48;
		write(1, &c, 1);
	}
}

void	ft_write_comb(int a, int b)
{
	if (a != b)
	{
		if (a < 10)
			write(1, "0", 1);
		ft_putnbr(a);
		write(1, " ", 1);
		if (b < 10)
			write(1, "0", 1);
		ft_putnbr(b);
		if (a != 98)
			write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < 100)
	{
		while (b < 100)
		{
			ft_write_comb(a, b);
			b++;
		}
		a++;
		b = a + 1;
	}
}
/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
