/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:56:44 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/09 16:46:13 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// atoi da copiare
//
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
// tutto atoi si mette file e si include nel mkfile
//
int	ft_putstrerr(char *str)
{
	str--;
	while (*(++str))
		write(2, str, 1);
	return (1);
}

void	ft_putfilename(char *str)
{
	write(1, "==> ", 4);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, " <==\n", 5);
}

// capire se va fatta la roba di B, MB, ecc ecc
int	ft_filesize(int fd, int size)
{
	int readBytes;
	int  totalBytes;
	char	*buffer;

	readBytes = 0;
	totalBytes = 0;
	buffer = (char *)malloc((totalBytes) * sizeof(char));
	while (readBytes == totalBytes)
	{
	free(buffer);
	buffer = (char *)malloc((totalBytes) * sizeof(char));
	readBytes = read(fd, buffer, totalBytes);
	totalBytes++;
	}
	free (buffer);
	return (readBytes);
}


int	ft_tail_read(int a, char *path, int size)
{
	int		readBytes;
	int		fd;
	int		i;
	char	*buffer;

	buffer = (char *)malloc(size * sizeof(char));
	if (buffer == NULL)
		return ;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstrerr(strerror(errno)));	
	readBytes = read(fd, buffer, size);
	if (readBytes > size)
		i = readBytes - size;
	if (a == 1)
		ft_putfilename(path);
	printf("%d\n", readBytes);
	while (i < readBytes)
	{
		write(1, &buffer[i], 1);
		i++;
	}
	close(fd);
	free(buffer);
}

int	main(int ac, char **av)
{
	int	j;
	int	a;
	int	size;
 
	j = 0;
	a = 0;
	size = 0;
	if (ac > 4)
		a = 1;
	while (j++ < ac)
	{
		if (ft_strcmp(av[j], "-c") == 0)
			size = ft_atoi(av[j]);
	}
	while (j < ac)
	{
		if (ft_strcmp(av[j], "-c") == 0)
			j += 2;
		if (j < ac)
		ft_tail_read(a, &av[j], size);
		j++;
	}
	return (0);
}
