/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:12:43 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/25 17:01:12 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	char	*start;

	start = str;
	while (*str != '\0')
	{
		if (str == start && *str >= 'a' && *str <= 'z')
			*str -= 32;
		else if (str != start)
		{//da fixare
			   if(*(str -1) < ' ' && *str >= 'a' && *str <= 'z')
			   	   *str -= 32;
		else if (*(str -1) < ' ' && *str >= 'A' && *str <= 'Z')
			*str += 32;
		else if (*(str -1) > '+' && *str >= 'a' && *str <= 'z')
			*str -= 32;
		else if (*(str -1) != '+' && *str >= 'A' && *str <= 'Z')
			*str += 32;
		else if (*(str -1) == '-' && *str >= 'a' && *str <= 'z')
			*str -= 32;
		else if (*(str -1) != '-' && *str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
	str = start;
	return (str);
}
/*
int main(void)
{
        char *s;
	char str[21] = " g 4hola 12qzio NNcan";
	s = &str[0];
        ft_strcapitalize(s);
	return 0;
}*/
