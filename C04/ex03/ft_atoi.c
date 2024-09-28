/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:18:42 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/28 17:37:31 by lbarreca         ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int	sign;
	int	r;
	int	i;

	sign = 1;
	i = 0;
	r = 0;
	while (is_space(str[i]) == 1)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		i++;
	}
	return (r * sign);
}
