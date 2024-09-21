#include<unistd.h>

void ft_putstr(char *str)
{
	while(*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}
/*
int main(void)
{
	char *pippo="asdasdasd";
	ft_putstr(pippo);
	return 0;

	}
*/
