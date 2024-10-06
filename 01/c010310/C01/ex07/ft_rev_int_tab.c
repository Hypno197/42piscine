/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:18:25 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/03 20:53:34 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	start;
	int	end;

	end = size - 1;
	start = 0;
	while (start < end)
	{
		temp = tab[start];
		tab[start] = tab[end];
		tab[end] = temp;
		start++;
		end--;
	}
}
/*
int	main(void)
{
	int tab[] = {1, 2, 3, 4, 5};
	ft_rev_int_tab(tab, 5);
	for (int i = 0; i < 5; i++)
	printf("%d\n", *(tab + i));
	return (0);
}*/
