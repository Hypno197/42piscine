/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:38:53 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/25 16:12:01 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*start;
	unsigned int	c;

	c = 0;
	start = dest;
	while (*dest)
		dest++;
	while (*src && c < nb)
	{
		*dest = *src;
		dest++;
		src++;
		c++;
	}
	*dest = '\0';
	dest = start;
	return (dest);
}
/*
int main()
{
    char str[20] = "ciao mi chiamo ";
    ft_strncat(&str[0], "luca", 6);
    printf("%s\n", str);
    return 0;
}
*/
