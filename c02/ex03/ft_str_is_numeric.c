//manca headfer


int ft_str_is_alpha(char *str)
{
        while(*str != '\0')
        {
        if(*str < '0' || *str > '9')
                return 0;
	str++;
        }
        return 1;
}
