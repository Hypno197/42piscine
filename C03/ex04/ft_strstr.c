/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:41:30 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/25 12:13:13 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char *ft_strstr(char *str, char *to_find)
{
	char	*start;

	if (*to_find == '\0')
		return (str);
	while(*str)
	{
		if (*to_find == *str)
			start = str;
		while (*to_find == *str)
			{
				to_find++;
				str++;
				if (*to_find == '\0')
				{
					return (start);	
				}		
			}
		str++;
	}
	return (NULL);
}
/*
int main()
{
	char	*str = ft_strstr("ma porco il dio cane842758G/&!£G$(( 42 1337 Network 2021 piscine Benguerir Khouribga 283462873427 ","42 1337 Network 2021 piscine Benguerir Khouribga");
	printf("%s\n", str); 

}
*/
