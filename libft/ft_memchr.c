void	*ft_memchr(const void *s, int	c, size_t n)
{
	size_t	i;
	const unsigned char	*str;
	unsigned char d;

	str = (const unsigned char *)s;
	d = (unsigned char)c;
	i = 0;
	while(i < n)
	{
		if(str[i] == d)
		{
			return ((void *)&s[i]);
		}
		i++;
	}	
	return (NULL);
}
