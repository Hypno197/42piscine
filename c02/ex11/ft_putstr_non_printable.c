/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:57:12 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/23 17:19:19 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//fixare i valori da dec a ascii!!

void ft_putstr_non_printable(char *str)
{
	int	c;
	int	d;
	
	c = 0;
	d = 0;
	while(*str != '\0')
	{
		if(*str >= ' ')
		write(1, str, 1);
		else
		{
			c = *str;
			write(1, "\\", 1);
			d = (c / 16) + '0';
			write(1, &d, 1);
			d = (c % 16);
			if (d > 9)
				d = d % 10 + 'a';
			else
				d = d + '0';
			write(1, &d, 1);
		}
		str++;
	}
}
/*
int main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
		return 0;
}*/
