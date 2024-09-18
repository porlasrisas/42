char	*ft_strrchr(const char *s, int	c)
{
	int	i;

	i = 0;
	while(s[i] != '\0')
		i++;
	if(c == '\0')
		return (char *)&s[i];	
	while(i - 1 >= 0)
	{
		if(s[i] == (char)c)
		{
			return (char *)&s[i];
		}
		i--;
	}
	return (NULL);
}
