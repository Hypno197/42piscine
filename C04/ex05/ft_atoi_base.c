/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:08:36 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/28 17:37:07 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char str)
{
	if (str == ' ' || str == '\n' || str == '\f')
		return (1);
	else if (str == '\v' || str == '\t' || str == '\r')
		return (1);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		while (str[c] != '\0')
		{
			if ((str[i] == str[c] && i != c) || str[c] == ' ')
				return (0);
			if (str[c] == '+' || str[c] == '-')
				return (0);
			c++;
		}
		c = 0;
		i++;
	}
	return (i);
}

int	chkbase(char d, char *base)
{
	int	i;

	i = 0;
	while (*base)
	{
		if (base[i] == d)
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	bl;
	int	sign;
	int	res;
	int	val;

	sign = 1;
	res = 0;
	bl = ft_strlen(base);
	if (bl < 2)
		return (0);
	while (is_space(*str) == 1)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str)
	{
		val = chkbase(*str, base);
		res = (res * bl) + val;
		str++;
	}
	return (res * sign);
}
