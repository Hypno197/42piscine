/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:59:44 by lbarreca          #+#    #+#             */
/*   Updated: 2024/09/25 18:22:39 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	c;

	c = 0;
	while (*str != '\0')
	{
		str++;
		c++;
	}
	return (c);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	offset;

	d_len = ft_strlen(dest);
	offset = d_len;
	while (*src && offset < size)
	{
		*(dest + offset) = *src;
		offset++;
		src++;
		if (offset == size - 1)
			break ;
	}
	*(dest + offset) = '\0';
	d_len += offset;
	return (d_len);
}
