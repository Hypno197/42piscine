/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:12:43 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/03 21:10:24 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*start;

	start = str;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
	str = start;
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	char	*start;

	start = str;
	str = ft_strlowcase(str);
	while (*str != '\0')
	{
		if (str == start && *str >= 'a' && *str <= 'z')
			*str -= 32;
		else if (*(str - 1) < 48 || (*(str - 1) > 57 && *(str - 1) < 65))
		{
			if (*str >= 'a' && *str <= 'z')
				*str -= 32;
		}
		else if ((*(str - 1) > 90 && *(str - 1) < 97) || *(str - 1) > 122)
			if (*str >= 'a' && *str <= 'z')
				*str -= 32;
		str++;
	}
	str = start;
	return (str);
}
/*
int	main(void)
{
		char *s;
	char str[21] = " g 4hola 12qzio NNcan";
	s = &str[0];
		ft_strcapitalize(s);
	return (0);
}*/
