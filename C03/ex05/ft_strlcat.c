/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:59:44 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/26 01:25:51 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
unsigned int	ft_strlen(char *str)
{
	unsigned int	c;

	c = 0;
	while (*str != '\0')
	{
		str++;
		c++;
	}
	return (c);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	offset;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	offset = d_len;
	if (d_len > size)
		return (size + s_len);
	while (offset < size)
	{
		*(dest + offset) = *src;
		offset++;
		src++;
	}
	if (*src == '\0' && offset < size)
		*dest = *src;
	d_len += s_len;
	return (d_len);
}
/*
int main(){
	char dst[40] = "ciao miiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
	char src[12] = "chiamo luca";
   int paolo = ft_strlcat( &dst[0], &src[0], 5);
	printf("%s\n", &dst[0]);
	printf("%d\n", paolo);
 return 0;	
}*/
