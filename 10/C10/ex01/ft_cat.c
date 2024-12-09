#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int	ft_putstr(char *str)
{
	str--;
	while (*(++str))
		write(1, str, 1);
	return (1);
}
int	main(int ac, char **av)
{
	int fd;
	int readBytes;
	char buffer[30720];
	int i;
    int j;

	if (ac == 1)
		return (ft_putstr(strerror(errno)));
	j = -1;
    while(++j < 30720)
        buffer[j] = '\0';
    j = 1;
    while (j < ac)
	{
    i = -1;
    fd = open(av[j], O_RDONLY);
	if (fd == -1)
		return (ft_putstr(strerror(errno)));
	readBytes = read(fd, buffer, 30720);
	while (buffer[++i])
		write(1, &buffer[i], 1);
	close(fd);
    j++;
    }
    return (0);
}
