#include <unistd.h>

char *ft_strcapitalize(char *str)
{
        char *start;
	
	//char c;

        start = str;
        while(*str != '\0')
        {
	if(str == start && *str >= 'a' && *str <= 'z')
	{
	*str = *str + 1;
	//	c = *str;
	//	c = c + 1;
	//	*str = c;
	}
	/*else if(*(str-1) == ' ' && *str >= 'a' && *str <= 'z')
	{
		 c = *str;
                c -= 'v';
                *str = c;
	}*/
	write(1, str, 1);
	str++;
        }
        str = start;
        return str;
}

int main(void)
{
        char *s = "hola zio can";
        ft_strcapitalize(s);
        //printf("%p\n", s);
	return 0;
}
//provare *(str-1)
