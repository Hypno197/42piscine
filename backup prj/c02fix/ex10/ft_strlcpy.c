/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:53:02 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/24 17:34:26 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	ld;

	ld = 0;
	if (size < 0)
	{
		while (*(src + ld) != '\0')
		{
			if (ld == size)
			{
				ld--;
				break ;
			}
			*(dest + ld) = *(src + ld);
			ld++;
		}
	}
	*(dest + ld) = '\0';
	while (*(src + ld) != '\0')
		ld++;
	return (ld);
}
