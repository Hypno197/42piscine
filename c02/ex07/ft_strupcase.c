char *ft_strupcase(char *str)
{
	char *start;

	start = str;
        while(*str != '\0')
        {
        if(*str >= 'a' && *str <= 'z')
                *str -= 32;
	str++;
        }
	str = start;
        return *str;
}
