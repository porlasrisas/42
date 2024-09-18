char	*ft_strnstr(const char *haystack, const char	*needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	if (len == '\0')
		return (NULL);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] != '\0' && (i + j) < len)
		{
			while (haystack[i + j] == needle[j] && (i + j) < len 
				&& needle[j] != '\0')
				j++;
			if (needle[j] == '\0')
				return((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
