/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:54:43 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/04 22:31:54 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

void	ft_putstr(char *str)
{
	str--;
	while (*(++str))
		write(1, str, 1);
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = (nb * -1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		c = nb + 48;
		write(1, &c, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		ft_putstr(par[i].copy);
		i++;
	}
	return ;
}
