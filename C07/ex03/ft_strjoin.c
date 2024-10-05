/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 02:15:33 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/03 12:30:00 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strcat(char *dest, char *src, char *sep)
{
	char	*start;

	start = dest;
	while (*dest)
		dest++;
	while (*sep)
	{
		*dest = *sep;
		dest++;
		sep++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	dest = start;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		totalsize;
	char	*dest;

	i = 0;
	totalsize = 0;
	if (size == 0)
		return ((char *)malloc(1 * sizeof(char)));
	totalsize += ft_strlen(strs[i]) * size + ft_strlen(sep) * size - 1;
	dest = (char *)malloc(totalsize * sizeof(char));
	dest[0] = '\0';
	i = 0;
	while (i < size)
	{
		if (i == 0)
			dest = ft_strcat(dest, strs[i], "");
		else
			dest = ft_strcat(dest, strs[i], sep);
		i++;
	}
	return (dest);
}
