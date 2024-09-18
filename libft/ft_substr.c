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
char	*ft_substr(char const	*s, unsigned int	start, size_t	len)
{
	char *s2;
	size_t	i;

	i = 0;
	if(s ==  NULL)
		return (NULL);
	if(start >= ft_strlen(s))
		len = 0;
	else if(len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	s2 = (char *)malloc(len + 1);
	if(s2 == NULL)
		return (NULL);
	while(i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
