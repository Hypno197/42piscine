/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:50:05 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/25 16:09:50 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		i++;
	}
	if (i == n)
		i--;
	return (s1[i] - s2[i]);
}
/*
int main(){
        char *s1 = "ABCCD", *s2= "ABCCC";
        int n = ft_strncmp(s1, s2, 3);
        printf("%d\n", n);
        return 0;
}
*/
