/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.roma42.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:56:44 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/09 14:30:04 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

//atoi da copiare
//
int     is_space(char str)
{
        if (str == ' ' || str == '\n' || str == '\f')
                return (1);
        else if (str == '\v' || str == '\t' || str == '\r')
                return (1);
        else
                return (0);
}

int     ft_atoi(char *str)
{
        int     sign;
        int     r;
        int     i;

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

int     ft_strcmp(char *s1, char *s2)
{
        int     i;

        i = 0;
        while (s1[i] == s2[i] && s1[i] != '\0')
        {
                i++;
        }
        return (s1[i] - s2[i]);
}
//tutto atoi si mette file e si include nel mkfile
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
		write(1, str, 1);
	write(1, " <==\n", 5);
}

//capire se va fatta la roba di B, MB, ecc ecc
int	ft_tail_size(char **av, int ac)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (ft_strcmp(av[i], "-c") == 0  && i < ac)
		i++;
	size = atoi(av[i]);
	return size;
}

int	ft_tail_read(int a, char *path, int size, char *buffer)
{
		int readBytes;
		int fd;
		int i;

		fd= open(path, O_RDONLY);
		if (fd == -1)
			return (ft_putstrerr(strerror(errno)));
		readBytes = read(fd, buffer, size);
		if(readBytes > size)
		i = readBytes - size;
		if (a == 1)
			ft_putfilename(path);
		while (i < readBytes)
		{
			write(1, &buffer[i], 1);
			i++;
		}
		close(fd);
		return 0;
}

int	main(int ac, char **av)
{
	char	*buffer;
	int		j;
	int		a;

	j = 1;
	a = 0;
	buffer = (char *)malloc(ft_tail_size(av, ac) * sizeof(char));
	if(buffer == NULL)
		return (1); 
	if(ac > 4)
		a = 1;
		int mario = ft_tail_size(av, ac);
		printf("%d\n", mario);
	while (j < ac)
	{
		write(1, "p", 1);
		//if(ft_strcmp(av[j], "-c") == 0)
		//	j += 2
		ft_tail_read(a, av[j], ft_tail_size(av, ac), buffer);
		j++;
	}
	return (0);
}
