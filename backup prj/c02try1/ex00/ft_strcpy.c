/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:50:21 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/24 14:39:45 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
char	*ft_strcpy(char *dest, char *src)
{
	char	*n;

	n = dest;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	dest = n;
	return (dest);
}
/* 
int main()
{
    char str1[20] = "Hello";
    char str2[20];
 
    ft_strcpy(str2, str1);
 
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
 
    return 0;
}*/
