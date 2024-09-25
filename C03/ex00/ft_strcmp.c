/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:49:44 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/24 22:49:52 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int ft_strcmp(char *s1, char *s2)
{
	int	a;
	
	a = 0;
	while (*s1)
	{
		a += *s1;
		s1++;
	}
	while (*s2)
	{	
		a -= *s2;
		if (a < 0)
			return (2);
		s2++;
	}
	if(a == 0)
		return (0);
	return (1);
}
/*
int main(){
	char *s1 = "ABC", *s2= "ABCCC";
	int n = ft_strcmp(s1, s2);
	printf("%d\n", n);
	return 0;
}*/
