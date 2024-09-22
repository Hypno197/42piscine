char *ft_strlowcase(char *str)
{
        char *start;

        start = str;
        while(*str != '\0')
        {
        if(*str >= 'A' && *str <= 'Z')
                *str += 32;
        str++;
        }
        str = start;
        return *str;
}
