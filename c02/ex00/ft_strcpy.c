//manca header

char	*ft_strcpy(char *dest, char *src)
{
	char	*n;
	
	n = dest;
	while(*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	dest = n;
	return *dest;
}
