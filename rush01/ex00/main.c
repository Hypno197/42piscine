#include <stdio.h>
/*
int chkcharh(char *linea)
{
	int	
}
**matrix
matrix = malloc(4(sizeof(*char)));
matrix[0] = "";
*/
char *extrval(char *str)
{
	int	i;
	int	j;
	char strex[16];

	i=0;
	j=0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <='9')
		{
			strex[j];
			j++;
		}
		i++;
	}
	return strex;
}



int main(int ac, char **av)
{
	char	*v;
	
	if (ac != 2)
		return 0;
	v = extrval(av[1]);
	printf("%s\n", v);
	return 0;
}
