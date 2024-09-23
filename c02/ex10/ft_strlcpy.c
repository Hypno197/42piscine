
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	ld;

	ld = 0;
	while (*(src+ld) != '\0' && ld < size)
	{
		*(dest+ld) = *(src+ld);
		ld++;
	}
	*(dest+ld) = '\0';
	while (*(src+ld) != '\0')
		ld++;
	return (ld);
}
