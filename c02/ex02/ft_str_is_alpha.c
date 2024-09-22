//header

//#include <stdio.h>

int ft_str_is_alpha(char *str)
{
	while(*str != '\0')
	{
	if(*str < 'A' || *str > 'Z' && *str < 'a' || *str > 'z')
		return 1;	
	str++;
	}
	return 0;
}
/*
int main()
{	
	char *s = "hola";
	int n = ft_str_is_alpha(s);
	printf("%d\n", n);

}
*/
