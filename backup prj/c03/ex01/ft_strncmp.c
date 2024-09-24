/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:45:12 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/24 14:45:15 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	c;
	int		a;

	a = 0;
	c = 0;
	while (*s1 && c < n)
	{
		a += *s1;
		s1++;
		c++;
	}
	c = 0;
	while (*s2 && c < n)
	{
		a -= *s2;
		if (a < 0)
			return (2);
		s2++;
		c++;
	}
	if(a == 0)
		return (0);
	return (1);
}
/*
int main(){
        char *s1 = "}}C", *s2= "ABCCC";
        int n = ft_strncmp(s1, s2, 4);
        printf("%d\n", n);
        return 0;
}
*/
