char	*ft_strchr(const char *s, int	c)
{
	int	i;

	i = 0;
	if(c == '\0')
		return (char *)&s[i];	
	while(s[i] != '\0')
	{
		if(s[i] == (char)c)
		{
			return (char *)&s[i];
		}
		i++;
	}
	return (NULL);
}
