#include<unistd.h>

int ft_strlen(char *str)
{
	int	c = 0;
	while ( *str != '\0' )
	{
		c++;
	}
	return c;
}

int main(void)
{
	char a[] = "diomerda";
	char*  s = &a;
	ft_strlen(s);
	return 0;
}
