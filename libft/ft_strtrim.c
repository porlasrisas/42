#include <stdlib.h>
static size_t	ft_strlen(const	char	*s)
{
	size_t	i;

	i = 0;
	while(s[i] != '\0')
	{
		i++;
	}
	return (i);
}
static char	*ft_strchr(const char *s, int	c)
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
static size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	aux_len;

	i = 0;
	aux_len = 0;
	while(src[i] != '\0')
		i++;
	if(dstsize == 0)
		return (i);
	while(src[aux_len] != '\0' && aux_len < dstsize - 1)
	{
		dst[aux_len] = src[aux_len];
		aux_len++;
	}
	dst[aux_len] = '\0';
	return (i);
}
char	*ft_strtrim(char const	*s1, char const	*set)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (j >= 0 && ft_strchr(set, s1[j]) != NULL)
		j--; 
	if (i > j)
		result = (char *)malloc(1);
	else
		result = (char *)malloc((j - i + 2) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, &s1[i], j - i + 2);
	return (result);
}
