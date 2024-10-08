/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreca <lbarreca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 05:44:45 by lbarreca          #+#    #+#             */
/*   Updated: 2024/10/08 16:06:37 by lbarreca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int		fd;
	int		readBytes;
	char	buffer[10240];
	int		i;

	if (ac == 1)
		return ((write(2, "File name missing.\n", 19)) * 0 + 1);
	else if (ac > 2)
		return ((write(2, "Too many arguments.\n", 21)) * 0 + 1);
	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return ((write(2, "Cannot read file.\n", 19)) * 0 + 1);
	readBytes = read(fd, buffer, 10240);
	while (i < readBytes)
	{
		write(1, &buffer[i], 1);
		i++;
	}
	close(fd);
	return (0);
}
