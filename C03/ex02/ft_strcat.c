/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:39:07 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/25 11:39:08 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strcat(char *dest, char *src)
{
	char	*start;

	start = dest;
	while(*dest)
		dest++;
	while(*src)
	{
	*dest = *src;
	dest++;
	src++;
	}
	*dest = '\0';
	dest = start;
	return (dest);
}
/*
int main()
{	
	char str[20] = "ciao mi chiamo ";
	ft_strcat(&str[0], "luca");
	printf("%s\n", str);
	return 0;
}
*/
