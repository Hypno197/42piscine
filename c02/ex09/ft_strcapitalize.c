
char *ft_strcapitalize(char *str)
{
        char *start;
	
        start = str;
        while(*str != '\0')
        {
	if(str == start && *str >= 'a' && *str <= 'z')
	{
	*str -= 32;
	}
	else if(str != start && *(str-1) == ' ' && *str >= 'a' && *str <= 'z')
	{
		*str -= 32;
	}
	str++;
        }
        str = start;
        return str;
}
/*
int main(void)
{
        char *s;
	char str[21] = " g 4hola 12qzio NNcan";
	s = &str[0];
        ft_strcapitalize(s);
	return 0;
}*/
