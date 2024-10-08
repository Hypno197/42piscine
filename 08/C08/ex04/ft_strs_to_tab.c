/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 06:22:36 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/05 19:42:36 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
typedef struct s_stock_str
{
int size;
char *str;
char *copy;
} t_stock_str;
int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		str++;
		c++;
	}
	return (c);
}

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
	*dest = '\0';
	dest = n;
	return (dest);
}

void	*breakfree(int a, int i, char *strc, t_stock_str *strarr)
{
	if (!strc && a == 1)
	{
		while (i > 0)
		{
			free(strarr[--i].str);
			free(strarr[i].copy);
		}
		free(strarr);
	}
	else if (!strc && a == 2)
	{
		free(strarr[i].copy);
		while (i > 0)
		{
			free(strarr[--i].str);
			free(strarr[i].copy);
		}
		free(strarr);
	}
	return (NULL);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*strarr;

	i = 0;
	strarr = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!strarr)
		return (NULL);
	while (i < ac)
	{
		strarr[i].size = ft_strlen(av[i]);
		strarr[i].str = (char *)malloc((strarr[i].size + 1) * sizeof(char));
		if (!strarr[i].str)
			return (breakfree(1, i, strarr[i].str, strarr));
		ft_strcpy(strarr[i].str, av[i]);
		strarr[i].copy = (char *)malloc((strarr[i].size + 1) * sizeof(char));
		if (!strarr[i].copy)
			return (breakfree(2, i, strarr[i].copy, strarr));
		ft_strcpy(strarr[i].copy, av[i]);
		i++;
	}
	strarr[i].str = 0;
	return (strarr);
}
