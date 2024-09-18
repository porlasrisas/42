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

char	*ft_strdup(const char	*s1)
{
	size_t	len;
	size_t	i;
	char	*copy;
	i = 0;
	len = ft_strlen(s1);
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);
 	while(s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
