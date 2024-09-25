/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:49:44 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/25 16:02:59 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int main(){
	char *s1 = "ABC", *s2= "ABCCC";
	int n = ft_strcmp(s1, s2);
	printf("%d\n", n);
	return 0;
}*/
