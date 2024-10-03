/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:39:22 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/03 12:16:35 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	a;	
	int		j;

	a = ' ';
	i = 0;
	while (a < 127)
	{
		j = 1;
		a++;
		while (j < argc)
		{
			if (argv[j][0] == a)
			{
				ft_putstr(argv[j]);
				write(1, "\n", 1);
			}
			j++;
		}
	}
	return (0);
}
