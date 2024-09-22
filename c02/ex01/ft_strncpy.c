//manca header

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
        char    *start;

	int counter;

	counter = 0;
        start = dest;
        while(*src != '\0' && counter < n)
        {
		*dest = *src;
		src++
		counter++;
               	dest++;
        }
	while(counter < n)
	{	
		*dest = '\0';
		src++;
		counter++;
		dest++;
	}
	dest = start;
	return *dest;
}
