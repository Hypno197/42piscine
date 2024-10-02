/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 01:05:32 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/02 01:19:59 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
    int c;

    c = 0;
    while (*str != '\0')
    {
        str++;
        c++;
    }
    return (c);
}
char *ft_strdup(char *src)
{
	int		srclen;
	char	*dest;
	int		i;

	i = 0;
	srclen = ft_strlen(src);
	dest = (char *)malloc(srclen * sizeof(char));
	if (dest != NULL)
	{
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
	}
	return NULL;
}
