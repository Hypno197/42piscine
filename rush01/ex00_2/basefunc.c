#include <unistd.h>

int ft_strlen(char *str)
{
    int c = 0;
    while (*str != '\0')
    {
        str++;
        c++;
    }
    return (c);
}

void ft_putstr(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}

void ft_putchar(char c)
{
    write(1, &c, 1);
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
