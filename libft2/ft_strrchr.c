char *ft_strrchr(char *str, char c)
{
	char *s;

	s = NULL;
	while(str)
	{
		if(*str == c)
			s = str;
		str++;
	}
	if(c == '\0')
        	return str;
	return s;
}
