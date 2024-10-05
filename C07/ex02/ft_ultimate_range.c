/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 01:28:24 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/03 12:25:32 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	i = 0;
	if (size <= 0)
	{
		*range = NULL;
		size = 0;
		return (size);
	}
	range[0] = (int *)malloc((max - min) * sizeof (int));
	if (range[0] == NULL)
		return (-1);
	while (i < size)
	{
		range[0][i] = min;
		min++;
		i++;
	}
	return (size);
}
