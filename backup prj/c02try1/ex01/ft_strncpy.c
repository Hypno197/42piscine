/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:51:01 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/24 14:39:18 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char				*start;
	unsigned int		counter;

	counter = 0;
	start = dest;
	while (*src != '\0' && counter < n)
	{
		*dest = *src;
		src++;
		counter++;
		dest++;
	}
	while (counter < n)
	{
		*dest = '\0';
		src++;
		counter++;
		dest++;
	}
	dest = start;
	return (dest);
}
/*
int main()
{
    char str1[20] = "Hello";
    char str2[20];

    ft_strncpy(str2, str1, 8);

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return 0;
}*/
