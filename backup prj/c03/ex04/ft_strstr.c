/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:41:30 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/25 16:15:09 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*start;
	char	*temp;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			start = str;
			temp = to_find;
			while (*temp && *str == *temp)
			{
				str++;
				temp++;
			}
			if (*temp == '\0')
				return (start);
			str = start;
		}
		str++;
	}
	return (NULL);
}
/*
int main()
{
	printf("%s\n", str); 

}
*/
